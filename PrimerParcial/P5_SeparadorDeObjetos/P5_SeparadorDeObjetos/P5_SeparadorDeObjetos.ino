#include <Servo.h>
#include <LiquidCrystal.h> 
LiquidCrystal lcd(22, 24, 26, 28, 30, 32);
Servo topMotor;
Servo botMotor;
//Sensor de color//////////////
const int s0 = 1;  
const int s1 = 2;  
const int s2 = 3;  
const int s3 = 4;  
const int out = 5;

int rojo = 0;  
int verde = 0;  
int azul = 0;
////////////////////////////////

void setup() {
  //pines del servo
  topMotor.attach(9);
  botMotor.attach(10);
  //pines del sensor
  pinMode(s0,OUTPUT);  
  pinMode(s1,OUTPUT);  
  pinMode(s2,OUTPUT);  
  pinMode(s3,OUTPUT);  
  pinMode(out,INPUT);   
  digitalWrite(s0,HIGH);  
  digitalWrite(s1,HIGH);
  //pos la pantalla, menso
  lcd.begin(16,2);
  lcd.home();
  lcd.print("xd");
  //inicializar posición de servomotores
  topMotor.write(0);
  delay(500);
  botMotor.write(0);
  delay(500); 
}

void loop() {
  reinicio:
  lcd.setCursor(0,0);
  lcd.print("Escaneo:");
  lcd.setCursor(0,1);
  lcd.print("3");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("2");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("1");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("0");
  color(); //lectura de color
  delay(150);
  
  bool compNoColor = comprobarNoColor(); //false significa que detectó un color, true que no detectó color
  delay(250);
  if( !compNoColor  )
  {
    bool compRojo  = comprobarRojo();
    bool compVerde = comprobarVerde();
    bool compAzul  = comprobarAzul();
      if(compRojo) //si detecta Rojo
        {
          moverBotMotor(30); //Mueve el conducto a 30°
          moverTopMotor();   //Arroja la pieza color rojo al conducto
        }
      if(compVerde)//si detecta Verde
        {
          moverBotMotor(90); //Mueve el conducto a 90°
          moverTopMotor();   //Arroja la pieza color verde al conducto
        }
      if(compAzul)//si detecta Azul
        {
          moverBotMotor(150); //Mueve el conducto a 150°
          moverTopMotor();    //Arroja la pieza color azul al conducto
        }
  }
  else
  {
   goto reinicio; //si no identificó color, a la etiqueta de reinicio para empezar otro escaneo de colores
  }

}
//Lectura de colores///////////////////////////////////////////
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);   
  rojo = pulseIn(out, (digitalRead(out) == HIGH) ? LOW : HIGH);
  digitalWrite(s3, HIGH);   
  azul = pulseIn(out, (digitalRead(out) == HIGH) ? LOW : HIGH);   
  digitalWrite(s2, HIGH);    
  verde = pulseIn(out, (digitalRead(out) == HIGH) ? LOW : HIGH);  
  //////////////////////////////////////////////////////////////
  Serial.print(rojo, DEC);
  Serial.print(" ");
  Serial.print(verde, DEC);
  Serial.print(" ");
  Serial.print(azul, DEC);
  Serial.println(" ");
}

//--comprobación de colores----------------------------------------
bool comprobarNoColor()
{
    if (rojo < verde && azul < verde && azul > 10)
    {
       lcd.clear();
       lcd.print("No color");
       Serial.println("No color");
       return true;
    }
    return false;
}
//-----------------------------------------------------------------Rojo
bool comprobarRojo()
{
  if (rojo < azul && verde > azul && rojo < 35)
  {
       lcd.clear();
       lcd.print("Rojo");
       Serial.println("Rojo");
       return  true;
  }
  return false;
}
//-----------------------------------------------------------------Verde
bool comprobarVerde()
{
  if (rojo > verde && azul > verde )  
  {  
       lcd.clear();  
       lcd.println("Verde");
       Serial.println("Verde");
       return true;
  }
  return false;
}
//----------------------------------------------------------------Azul
bool comprobarAzul()
{
  if (azul < rojo && azul < verde && verde < rojo)
  {  
       lcd.clear();
       lcd.println("Azul");
       Serial.println("Azul");
       return true;      
  }
  return false;
}
//*************************************Mover motores********************
void moverTopMotor()
{
  for(int i = 1; i <= 180; i++)
  {
    topMotor.write(i);
    delay(2);
  }
  delay(500);

  for(int i = 180; i >= 0; i++)
  {
    topMotor.write(i);
    delay(2);
  }
  delay(500);
}
//***********************************************************************
void moverBotMotor(int grados)
{
    botMotor.write(grados);
    delay(500);
}
