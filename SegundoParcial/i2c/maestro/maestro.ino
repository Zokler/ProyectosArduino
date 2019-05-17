#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

#include <Keypad.h>
const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad
char keymap[numRows][numCols]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'E', '0', 'F', 'D'}
};
byte rowPins[numRows] = {22,24,26,28}; 
byte colPins[numCols]= {30,32,34,36}; 
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
//-------------------------------------------------------------------------------;
char tecla;

#include <Wire.h>
int slaveId = 0 ;
void setup() {
  Serial.begin( 9600 ) ;
  while ( !Serial ) ;

  Wire.begin() ;

    lcd.begin(16,2);
    lcd.home();
    lcd.print("Slv 1: 1, Slv 2: 2");
}
void loop() {
  tecla = myKeypad.waitForKey();
  lcd.print(tecla);
  
    switch ( tecla ) {
      case '1' :
        slaveId = 1 ;
        lcd.println( " Conectado slave1" ) ;
        lcd.clear();
        lcd.println(" Envie un dato") ;
        tecla = myKeypad.waitForKey();
        return ;
      case '2' :
        slaveId = 2 ;
        lcd.println( " Conectado slave2" ) ;
        lcd.clear();
        lcd.println(" Envie un dato") ;
        tecla = myKeypad.waitForKey();
        return ;
    }

    if ( slaveId == 1 ) {
      Wire.beginTransmission( slaveId ) ;
      lcd.clear();
      lcd.print("Slave 1: ");
      lcd.print(tecla);
      int n = tecla;
      Wire.write( n ) ;
      Wire.endTransmission() ;
    }
    if ( slaveId == 2 ) {
      Wire.beginTransmission( slaveId ) ;
      lcd.clear();
      lcd.print("Slave 2: ");
      lcd.print(tecla);
      int n = tecla;
      Wire.write( n ) ;
      Wire.endTransmission() ;
    }
  
}
