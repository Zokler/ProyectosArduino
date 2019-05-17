//variables motores:
int in1 = 8; //pin 8
int in2 = 9; //pin 9
//int enA = 10; //pin 10
int in3 = 10;
int in4 = 11;
int estado=0;

void setup(){
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop(){
 if(Serial.available()>0){
 estado = Serial.read();
 Serial.print(estado + " ");
 }
 if (estado =='1'){
  //AVANZAR
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); //combinacion para avanzar
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); //combinacion para avanzar
   
  }
if(estado=='2'){
  //ATRAS
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW); //combinacion para avanzar
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); //combinacion para avanzar
  }
  if(estado=='3'){
   //DERECHA
   
  }
  if(estado=='4'){
    //IZQUIERDA
   
  }
  if(estado=='6'){
    //PARAR
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW); //combinacion para avanzar
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW); //combinacion para avanzar
  }

  
}  
