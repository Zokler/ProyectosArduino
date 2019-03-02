#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int bits[6], inicio;

void setup() 
{
  for(int numPin = 0; numPin <=7; numPin++)
    {
      pinMode(numPin, INPUT);
    }
    
    lcd.begin(16,2);
    lcd.home();
    lcd.print("Key: ");
}

void loop() 
{
  inicio = digitalRead(7);
  if(inicio == 1)
  {
        bits[0] = digitalRead(0);
        bits[1] = digitalRead(1);
        bits[2] = digitalRead(2);
        bits[3] = digitalRead(3);
        bits[4] = digitalRead(4);
        bits[5] = digitalRead(5);
        bits[6] = digitalRead(6);
        //bits[7] = digitalRead(7);
        
        lcd.setCursor(0,1);
        conversion();
  }
}
//---------------------------------------
void conversion()
{
  int valorAscii = ( (bits[0]*1)+(bits[1]*2)+(bits[2]*4)+(bits[3]*8)+(bits[4]*16)+(bits[5]*32)+(bits[6]*64) );
  char Ascii = valorAscii;
  
  lcd.print(Ascii);
}
