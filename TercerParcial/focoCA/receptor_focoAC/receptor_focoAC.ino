
#include<LiquidCrystal.h> //Libreria para el LCD

int AC_LOAD = 7;    // Output to Opto Triac pin
int dimming = 0;  // Dimming level (0-128)  0 = ON, 128 = OFF

void setup() {
  Serial.begin(9600);
  pinMode(AC_LOAD, OUTPUT);
  attachInterrupt(1, zero_crosss_int, RISING); 
}

void loop(){
  //verificamos si hay un dato valido en el RF
  if (Serial.available()){
    int dato = Serial.read();
    Serial.print((char)dato);
    if ((char)dato == '0'){
      dimming = 0;
    }
    else if ((char)dato == '1'){
      
      dimming = 120;

    }
    else if ((char)dato == '2'){
      dimming = 110;

    }
    else if((char)dato == '3'){
      dimming = 95;

    }
     else if ((char)dato == '4'){
      dimming = 80;
    }
    else if ((char)dato == '5'){
      dimming = 65;
    }
    else if((char)dato == '6'){
      dimming = 50;

    }
    else if ((char)dato == '7'){
      dimming = 10;

    }
    else {

    }
  
  }
  //zero_crosss_int(); 
}

void zero_crosss_int()  // function to be fired at the zero crossing to dim the light
{
  int dimtime = (65*dimming);    // For 60Hz =>65   
  delayMicroseconds(dimtime);    // Off cycle
  digitalWrite(AC_LOAD, HIGH);   // triac firing
  delayMicroseconds(8.33);         // triac On propagation delay (for 60Hz use 8.33)
  digitalWrite(AC_LOAD, LOW);    // triac Off
}
