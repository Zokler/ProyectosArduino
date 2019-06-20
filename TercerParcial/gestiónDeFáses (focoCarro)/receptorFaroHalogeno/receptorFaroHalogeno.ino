int pin = 9;
int val = 0;

void setup() {
Serial.begin(9600);
pinMode(pin,OUTPUT);
digitalWrite(pin,HIGH);
}

  int x=0;
void loop() {
 
  if(Serial.available()>0){
    delay(100);
     x = Serial.read(); 
  }
   Serial.print(x);
   if(x==0){
      analogWrite(pin,0);
      Serial.print(x);
    }else if(x==1){
        analogWrite(pin,63);
        Serial.print(x);
      }else if(x==2){
         analogWrite(pin,126);
         Serial.print(x);
        }else if(x==3){
          analogWrite(pin,189);
          Serial.print(x);
          }else if(x==4){
            analogWrite(pin,255);
            Serial.print(x);
            }
}
