#include <Wire.h>
// preparing for which slave device
// need to be connected
int slaveId = 0 ;
void setup() {
  Serial.begin( 9600 ) ;
  while ( !Serial ) ;
  // Run as I2C Master
  Wire.begin() ;
}
void loop() {
  if ( Serial.available() ) {
    // console terminal read per character
    char ch = Serial.read() ;
    // map key ‘1’ for slave device id #1
    // map key ‘2’ for slave device id #2
    switch ( ch ) {
      case '1' :
        slaveId = 1 ;
        Serial.println( " > connected to slave id #1" ) ;
        return ;
      case '2' :
        slaveId = 2 ;
        Serial.println( " > connected to slave id #2" ) ;
        return ;
    }
    // try to send the character to
    // the specific slave id
    if ( slaveId == 1 ) {
      Wire.beginTransmission( slaveId ) ;
      int n = 65;
      Wire.write( n ) ;
      Wire.endTransmission() ;
    }
    if ( slaveId == 2 ) {
      Wire.beginTransmission( slaveId ) ;
      Wire.write( 65 ) ;
      Wire.endTransmission() ;
    }
  }
}
