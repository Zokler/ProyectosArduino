#include <Wire.h>
void setup() {
  Serial.begin( 9600 ) ;
  while ( !Serial ) ;
  // run as I2C Slave with id = 1
  int slaveId = 1 ;
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
    Serial.print( xd ) ;
  }
}
