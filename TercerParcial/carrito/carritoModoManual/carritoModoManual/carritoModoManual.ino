//variables motores:
int enA = 2; 
int enB = 3; 
int in1 = 47;
int in2 = 49; 
int in3 = 51;
int in4 = 53;

void setup() {
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

}

void loop() {
   if(Serial.available()>0)
   {
      estado = Serial.read();
      Serial.print(estado + " ");
   }
   
   if (estado =='1')
   {
    //AVANZAR
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH); //combinacion para avanzar
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH); //combinacion para avanzar
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
