int led13=13;
int estado=0;

void setup(){
  Serial.begin(9600);
  pinMode(led13,OUTPUT);
}

void loop(){
 if(Serial.available()>0){
 estado = Serial.read();
 Serial.print(estado + " ");
 }
 if (estado =='1'){
   digitalWrite(led13,HIGH);
  }
if(estado=='2'){
   digitalWrite(led13,LOW);
  }
}  
