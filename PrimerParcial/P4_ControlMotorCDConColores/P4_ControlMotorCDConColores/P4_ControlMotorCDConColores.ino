#include <LiquidCrystal.h>
LiquidCrystal lcd(48, 46, 44, 42, 40, 38);

const int s0 = 1;  
const int s1 = 2;  
const int s2 = 3;  
const int s3 = 4;  
const int out = 5;

boolean moradito=false;

int rojo = 0;  
int verde = 0;  
int azul = 0;
//SENSOR/////////////////

int in1 = 6; //pin 6
int in2 = 7; //pin 7
int enA = 8; //pin PWM AHH
//MOTOR/////////////////
void setup() {
   
  pinMode(s0,OUTPUT);  
  pinMode(s1,OUTPUT);  
  pinMode(s2,OUTPUT);  
  pinMode(s3,OUTPUT);  
  pinMode(out,INPUT);
  digitalWrite(s0,1);  
  digitalWrite(s1,0);
///////////////SENSOR///////////
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
///////////////SOLENOIDE//////// 
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.home();

}
void loop(){  
  color(); 
   Serial.print(" ");
  Serial.print(rojo, DEC);
  Serial.print(" ");
  Serial.print(verde, DEC);
  Serial.print(" ");
  Serial.print(azul, DEC);

  if (rojo > azul && azul < verde && azul > 10 && verde > 25)
    {
       moradito=false;
       lcd.clear();
       lcd.print("No color");
       digitalWrite(in1, LOW);
       digitalWrite(in2, LOW);
       analogWrite(enA, 0);
    }
  
  if (rojo < azul && verde > azul && rojo < 35)  //rojo motor rapido
    {
       moradito=false;
       lcd.clear();
       lcd.setCursor(0,0); 
       lcd.print("Rojo: rapido");
       digitalWrite(in1, HIGH);
       digitalWrite(in2, LOW);
       analogWrite(enA, 255);
       delay(5000);
    }
       
    if (azul < rojo && azul < verde && verde < rojo)//azul   
    {  
       moradito=false;
       lcd.clear();
       lcd.setCursor(0,0); 
       lcd.print("Azul: lento");
       digitalWrite(in1, HIGH);
       digitalWrite(in2, LOW);
       analogWrite(enA, 100);
       delay(250);     
    }  
  
    if (rojo > verde && azul > verde )  //verde
    {  
       moradito=false;
       lcd.clear();
       lcd.setCursor(0,0); 
       lcd.print("Verde: Freno");
       digitalWrite(in1, LOW);
       digitalWrite(in2, LOW);
       analogWrite(enA, 0);
       delay(250);
    }
     if (rojo < verde && azul < verde && rojo < 15 && rojo > 7)  //morado
    {  
       lcd.clear();
       lcd.setCursor(0,0); 
       lcd.print("Morado: Acelerar");
       digitalWrite(in1, LOW);
       digitalWrite(in2, HIGH); //combinacion para avanzar
       if(!moradito)
       {
         for(int i=10; i<256; i+=20)
         {
            analogWrite(enA, i);
            delay(500);
         }
         moradito=true;
       }
       else
       {
          analogWrite(enA, 255);
       }
       /*
       analogWrite(enA, 63);
       delay(50);
       analogWrite(enA, 126);
       delay(50);
       analogWrite(enA, 189);
       delay(50);
       analogWrite(enA, 255);
       delay(50);
       */
    }  
   Serial.println(" ");
  delay(1000);     
  }  
    
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);   
  rojo = pulseIn(out, (digitalRead(out) == HIGH) ? LOW : HIGH); 
  digitalWrite(s3, HIGH);   
  azul = pulseIn(out, (digitalRead(out) == HIGH) ? LOW : HIGH);  
  digitalWrite(s2, HIGH);    
  verde = pulseIn(out, (digitalRead(out) == HIGH) ? LOW : HIGH);  
  
  delay(1000);
}
