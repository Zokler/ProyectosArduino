#include <LiquidCrystal.h>
LiquidCrystal lcd(48, 46, 44, 42, 40, 38);

const int s0 = 1;  
const int s1 = 2;  
const int s2 = 3;  
const int s3 = 4;  
const int out = 5;

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
  
  if (rojo < azul && verde > azul && rojo < 35)
    {
       lcd.clear();
       lcd.setCursor(0,0); 
       lcd.print("Rojo: off");
       analogWrite(enA, 0);
       digitalWrite(in1, LOW);
       digitalWrite(in2, LOW);
       delay(250);
    }
      
     if (rojo < verde && azul < verde && rojo <34 && rojo > 7)  
    {  
       lcd.clear();
       lcd.setCursor(0,0); 
       lcd.print("Morado: on");
       analogWrite(enA, 255);
       digitalWrite(in1, HIGH);
       digitalWrite(in2, LOW);
       delay(250);
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
