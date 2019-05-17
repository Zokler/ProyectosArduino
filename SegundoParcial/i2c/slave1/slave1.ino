#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
void setup() {
  Serial.begin( 9600 ) ;
  while ( !Serial ) ;
  // run as I2C Slave with id = 1
  int slaveId = 2 ;
  Wire.begin( slaveId ) ;
  // setup callback function
  //Wire.onReceive( onWireReceive ) ;
}
void loop() {
  // nothing to do
    Wire.onReceive( onWireReceive ) ;

}
void onWireReceive( int howMany ) {
  while ( Wire.available() ) {
    // print back all the characters
    // into console terminal
    int ch = Wire.read() ;
    char xd = ch;
    Serial.print(xd);
    lcd.print( xd ) ;
  }
}
