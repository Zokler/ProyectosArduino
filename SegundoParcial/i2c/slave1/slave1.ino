#include <Wire.h>
void setup() {
  Serial.begin( 9600 ) ;
  while ( !Serial ) ;
  // run as I2C Slave with id = 1
  int slaveId = 1 ;
  Wire.begin( slaveId ) ;
  // setup callback function
  Wire.onReceive( onWireReceive ) ;
}
void loop() {
  // nothing to do
}
void onWireReceive( int howMany ) {
  while ( Wire.available() ) {
    // print back all the characters
    // into console terminal
    char ch = Wire.read() ;
    Serial.print( ch ) ;
  }
}
