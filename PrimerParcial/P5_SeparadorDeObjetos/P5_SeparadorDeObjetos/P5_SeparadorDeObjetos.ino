#include <Servo.h>
#include <LiquidCrystal.h> 
//LiquidCrystal Serial(22, 24, 26, 28, 30, 32);
Servo topMotor;
Servo botMotor;
//Sensor de color//////////////
const int s0 = 1;  
const int s1 = 2;  
const int s2 = 3;  
const int s3 = 4;  
const int out = 5;

bool compNoColor;
int rojo = 0;  
int verde = 0;  
int azul = 0;
////////////////////////////////

void setup() {
  Serial.begin(115200);
  //pines del servo
  topMotor.attach(9);
  botMotor.attach(8);
  //pines del sensor
  pinMode(s0,OUTPUT);  
  pinMode(s1,OUTPUT);  
  pinMode(s2,OUTPUT);  
  pinMode(s3,OUTPUT);  
  pinMode(out,INPUT);   
  digitalWrite(s0,1);  
  digitalWrite(s1,0);
  //pos la pantalla, menso
  //Serial.begin(16,2);
//  Serial.home();
  Serial.print("xd");
  //inicializar posición de servomotores
  topMotor.write(180);
  delay(500);
  botMotor.write(180);
  delay(500); 
}

void loop() {
  reinicio:
  //(0,0);
  Serial.print("Escaneo:");
  //(0,1);
  Serial.print("3");
  delay(1000);
  //(0,1);
  Serial.print("2");
  delay(1000);
  //(0,1);
  Serial.print("1");
  delay(1000);
  //(0,1);
  Serial.println("0");
  color(); //lectura de color
  delay(150);
  
  compNoColor = comprobarNoColor(); //false significa que detectó un color, true que no detectó color
  delay(250);
  if( !compNoColor  )
  {
    bool compRojo  = comprobarRojo();
    bool compVerde = comprobarVerde();
    bool compAzul  = comprobarAzul();
    
      if(compRojo) //si detecta Rojo
        {
          moverBotMotor(0); //Mueve el conducto a 30°
          delay(1500);
          moverTopMotor();   //Arroja la pieza color rojo al conducto
        }
      if(compVerde)//si detecta Verde
        {
          moverBotMotor(90); //Mueve el conducto a 90°
          delay(1500);
          moverTopMotor();   //Arroja la pieza color verde al conducto
        }
      if(compAzul)//si detecta Azul
        {
          moverBotMotor(40); //Mueve el conducto a 150°
          delay(1500);
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
 //   if (rojo < 10 && verde <160 && verde >140; azul >100 && azul <120)
   // {
//       Serial.clear();
     //  Serial.print("No color");
       Serial.println("No color");
       //return true;
    //}
    return false;
}
//-----------------------------------------------------------------Rojo
bool comprobarRojo()
{
  if (rojo > 55 && verde > 110 && verde < 135)
  {
//       Serial.clear();
       Serial.print("Rojo");
       Serial.println("Rojo");
       return  true;
  }
  return false;
}
//-----------------------------------------------------------------Verde
bool comprobarVerde()
{
  if (rojo > 7 && verde < 100 && azul < verde && rojo < 25)  
  {  
//       Serial.clear();  
       Serial.println("Verde");
       Serial.println("Verde");
       return true;
  }
  return false;
}
//----------------------------------------------------------------Azul
bool comprobarAzul()
{
  if (rojo > 30 && rojo < 55 && verde < 60 && verde > 20 && azul > rojo && azul > 19 && azul < 30) 
  {  
//       Serial.clear();
       Serial.println("Azul");
       Serial.println("Azul");
       return true;      
  }
  return false;
}
//*************************************Mover motores********************
void moverTopMotor()
{

  for(int i = 180; i >= 130; i--)
  {
    topMotor.write(i);
    delay(30);
  }
  delay(500);
    for(int i = 150; i <= 180; i++)
  {
    topMotor.write(i);
    delay(30);
  }
}
//***********************************************************************
void moverBotMotor(int grados)
{
    botMotor.write(grados);
    delay(500);
}
