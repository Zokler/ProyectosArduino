#include <LiquidCrystal.h>
LiquidCrystal lcd(48, 46, 44, 42, 40, 38);

const int s0 = 1;  
const int s1 = 2;  
const int s2 = 3;  
const int s3 = 4;  
const int out = 5;
const int rel= 6;
    
int rojo = 0;  
int verde = 0;  
int azul = 0;

bool encendido = false;

void setup(){  
  
  pinMode(s0,OUTPUT);  
  pinMode(s1,OUTPUT);  
  pinMode(s2,OUTPUT);  
  pinMode(s3,OUTPUT);  
  pinMode(rel, OUTPUT);
  pinMode(out,INPUT);
     
  digitalWrite(s0,HIGH);  
  digitalWrite(s1,HIGH);

  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.home();
}  

   
void loop(){  
  color(); 
 
  if (rojo < azul && verde > azul && rojo < 35
  && encendido == false)  //rojo enciende el foco
  {
   
  }
     
  if (azul < rojo && azul < verde && verde < rojo
  && encendido == true)//azul apaga el foco  
  {  
   lcd.clear();
   lcd.println("Azul: foco off");
   encendido = false;
   digitalWrite(rel, HIGH); //apaga el foco        
  }  

  if (rojo > verde && azul > verde )  
  {  
      lcd.clear();  
   lcd.println("v: foco on");
   encendido = true;
   digitalWrite(rel, LOW); //enciende foco  
  }  
 
  delay(1000);     
  }  
    
void color()  
{    
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
  Serial.println("////////////////");
  delay(1000);
}
