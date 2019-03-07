#include <LiquidCrystal.h>
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

const int s0 = 22;  
const int s1 = 24;  
const int s2 = 26;  
const int s3 = 28;  
const int out = 30;

int rojo = 0;  
int verde = 0;  
int azul = 0;
//SENSOR/////////////////

int in1 = 8; //pin 8
int in2 = 9; //pin 9
int enA = 10; //pin 10
//MOTOR/////////////////
void setup() {
   
  pinMode(s0,OUTPUT);  
  pinMode(s1,OUTPUT);  
  pinMode(s2,OUTPUT);  
  pinMode(s3,OUTPUT);  
  pinMode(out,INPUT);
  digitalWrite(s0,HIGH);  
  digitalWrite(s1,HIGH);
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
  
  if (rojo < azul && verde > azul && rojo < 35)  //rojo enciende el foco
    {
       Serial.println("////////////////////////////////////");  
       Serial.println("Rojo: on");
       analogWrite(enA, 255);
       digitalWrite(in1, HIGH);
       digitalWrite(in2, LOW);
    }
       
    if (azul < rojo && azul < verde && verde < rojo)//azul apaga el foco  
    {  
  //   /  lcd.clear();
       Serial.println("////////////////////////////////////");
       Serial.println("AZUL: on"); 
       analogWrite(enA, 255);
       digitalWrite(in1, LOW);
       digitalWrite(in2, LOW);      
    }  
  
    if (rojo > verde && azul > verde )  
    {  
  //     lcd.clear();
       Serial.println("////////////////////////////////////");  
       Serial.println("Verde: on");
       analogWrite(enA, 255);
       digitalWrite(in1, HIGH);
       digitalWrite(in2, LOW);
    }
     if (rojo < verde && azul < verde && rojo <34 && rojo > 7)  
    {  
  //     lcd.clear();
       Serial.println("////////////////////////////////////");  
       Serial.println("Morado: on");
       analogWrite(enA, 255);
       digitalWrite(in1, HIGH);
       digitalWrite(in2, LOW);
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
