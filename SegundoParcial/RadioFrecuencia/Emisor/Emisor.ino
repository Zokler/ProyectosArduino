#include <VirtualWire.h>
#include <Keypad.h>
const byte filas = 4;//Filas del teclado
const byte colums = 4;//Columnas del teclado
char keys [filas][colums] =//Define las teclas
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte fPins[filas] = {4,5,6,7};//Pines de conexion de las filas
byte cPins[colums] = {8,9,10,11};//Pines de conexion de las columnas

//Inicializacion del teclado
Keypad keypad = Keypad(makeKeymap(keys), fPins, cPins, filas, colums);
char key = NULL;
const int RF= 2;//Pin de conexion

void setup(){
    Serial.begin(9600);
    // Se inicializa el RF
    vw_setup(2000); // velocidad: Bits per segundo
    vw_set_tx_pin(RF); //Pin como salida para el RF
}

void loop(){
  key = keypad.getKey();
    if(key!= NO_KEY){
      char data[1];
      data[0]=key;
      //Enviamos el carácter recibido al RF
      vw_send((uint8_t*)data,sizeof(data));
      vw_wait_tx();
      Serial.println(key);
    }
    delay(200);
}
