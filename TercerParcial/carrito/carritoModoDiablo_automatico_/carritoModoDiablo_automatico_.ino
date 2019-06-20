//variables motores:
int enA = 2; 
int enB = 3; 
int in1 = 47;
int in2 = 49; 
//AHHHHHHHHHHHHHHHH
int in3 = 51;
int in4 = 53;

int trigger = 24;
int echo = 25;
float tiempo, distanciaa;


const int s0 = 8;  
const int s1 = 9;  
const int s2 = 10;  
const int s3 = 11;
const int out = 12;


const int ss0 = 4;  
const int ss1 = 5;  
const int ss2 = 6;  
const int ss3 = 7;
const int oout = 13;

int rojo = 0;  
int verde = 0;  
int azul = 0;

int rojo2 = 0;  
int verde2 = 0;  
int azul2 = 0;

int linea;

void setup(){
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(s0,OUTPUT);  
  pinMode(s1,OUTPUT);  
  pinMode(s2,OUTPUT);  
  pinMode(s3,OUTPUT);  
  pinMode(out,INPUT);

  pinMode(ss0,OUTPUT);  
  pinMode(ss1,OUTPUT);  
  pinMode(ss2,OUTPUT);  
  pinMode(ss3,OUTPUT);  
  pinMode(oout,INPUT);
     
  digitalWrite(s0,HIGH);  
  digitalWrite(s1,LOW);
  
  digitalWrite(ss0,HIGH);  
  digitalWrite(ss1,LOW);
  
  Serial.begin(9600);
}

void loop(){
  
  if(distancia())
  {
    avanzar();
  }
    else
    {
      girar();
    } 
   //delay(1000); //no te olvides de quitar estooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
  color(); 
  color2();
}  

void girar()
{
   //adelante
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); //combinacion para avanzar
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); //combinacion para avanzar
  
  analogWrite(enA, 180);
  analogWrite(enB, 180); 
}

void avanzar()
{
   //adelante
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); //combinacion para avanzar
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); //combinacion para avanzar
  
  analogWrite(enA, 255);
  analogWrite(enB, 255); 
}

void atras()
{
   //atras
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); //combinacion para avanzar
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); //combinacion para avanzar
  
  analogWrite(enA, 90);
  analogWrite(enB, 90); 
}
void modoDiablo1()
{
    digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); //combinacion para avanzar
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); //combinacion para avanzar
  
  analogWrite(enA, 180);
  analogWrite(enB, 180); 
  delay(1000);
  //girar como loco
    digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); //combinacion para avanzar
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); //combinacion para avanzar
  
  analogWrite(enA, 180);
  analogWrite(enB, 180); 
}

void modoDiablo2()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW); //combinacion para avanzar
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); //combinacion para avanzar
  
  analogWrite(enA, 180);
  analogWrite(enB, 180); 
  delay(1000);
  //girar como loco
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); //combinacion para avanzar
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); //combinacion para avanzar
  
  analogWrite(enA, 180);
  analogWrite(enB, 180); 
}
void parar()
{
   //adelante
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW); //combinacion para avanzar
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW); //combinacion para avanzar
  
  analogWrite(enA, 100);
  analogWrite(enB, 100); 
}

bool distancia()
{
  //delay(100);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  tiempo = pulseIn (echo, HIGH);
  distanciaa = (tiempo/2)/29.15;

   if(distanciaa > 40)
    {
      Serial.println(distanciaa);
       Serial.println("Estoy dando vueltas :3");
      return false;
    }
    Serial.println(distanciaa);
    Serial.println("Adelante :3");
  return true;
}

//si el detector de atrás detecta algo
void color()  
{ 
  Serial.println("///////Sensor 1/////////");  
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);   
  rojo = pulseIn(out, (digitalRead(out) == HIGH) ? LOW : HIGH);
  Serial.println(rojo, DEC); 
  digitalWrite(s3, HIGH);   
  azul = pulseIn(out, (digitalRead(out) == HIGH) ? LOW : HIGH);
  Serial.println(azul, DEC);   
  digitalWrite(s2, HIGH);    
  verde = pulseIn(out, (digitalRead(out) == HIGH) ? LOW : HIGH);  
  Serial.println(verde, DEC);
  Serial.println("///////Sensor 1/////////");

  if(azul > 45)
  {
    modoDiablo1();
    delay(300);
  }

}

//si el detector de delante detecta algo
void color2()  
{    
  
  Serial.println("////////Sensor 2////////");
  digitalWrite(ss2, LOW);  
  digitalWrite(ss3, LOW);   
  rojo2 = pulseIn(oout, (digitalRead(oout) == HIGH) ? LOW : HIGH);
  Serial.println(rojo2, DEC); 
  digitalWrite(ss3, HIGH);   
  azul2 = pulseIn(oout, (digitalRead(oout) == HIGH) ? LOW : HIGH);
  Serial.println(azul2, DEC);   
  digitalWrite(ss2, HIGH);    
  verde2 = pulseIn(oout, (digitalRead(oout) == HIGH) ? LOW : HIGH);  
  Serial.println(verde2, DEC);
  Serial.println("////////Sensor 2////////");

  if(azul2 > 45)
  {
    modoDiablo2();
    delay(300);
  }
  
}
