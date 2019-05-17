#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
void setup() {
  Serial.begin( 9600 ) ;
  while ( !Serial ) ;
  //Sólo cambiar el valor de slaveID por 1 o 2 según sea el slave a programar
  int slaveId = 2 ;
  Wire.begin( slaveId ) ;
}
void loop() {
    Wire.onReceive( onWireReceive ) ;

}
void onWireReceive( int howMany ) {
  while ( Wire.available() ) {
    int ch = Wire.read() ;
    char xd = ch;
    Serial.print(xd);
    lcd.print( xd ) ;
  }
}
