#include <Keypad.h>
const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad
char keymap[numRows][numCols]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'E', '0', 'F', 'D'}
};
byte rowPins[numRows] = {22,24,26,28}; 
byte colPins[numCols]= {30,32,34,36}; //A0, A1 PARA ARDUINO UNO
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
//-------------------------------------------------------------------------------;
char tecla;
int equivalenteAscii;
int bits[7];

void setup() 
{
  for(int numPin = 0; numPin < 8; numPin++)
    {
      pinMode(numPin, OUTPUT);
    }
  //pinMode(A3, OUTPUT); //A3, SE PODRÍA USAR EL PIN7 YA QUE NO SE NECESITARÁ PARA NINGÚN CÓDIGO ASCII DEL TECLADO
  //digitalWrite(7, 0);//A3
}

void loop() 
{
  tecla = myKeypad.waitForKey();
  equivalenteAscii = tecla;
  sendInAscii(equivalenteAscii);
  sendToArduino2();
}
//-----------Funciones-------------------------------------------------------------------------------
void sendInAscii(int asciiRecibido)
{
 for(int positionOfBit=0; positionOfBit<=7; positionOfBit++)
 {
    bits[positionOfBit]= bitRead(asciiRecibido, positionOfBit); //bitRead -> Del valor asciiRecibido , pon el bitX en bits[x]
 }
}
//---------------------------------------------------------------------------------------------------
void sendToArduino2()
{
  digitalWrite(0, bits[0]); //pon en el PIN0 el valor del BIT0
  digitalWrite(1, bits[1]);
  digitalWrite(2, bits[2]);
  digitalWrite(3, bits[3]);//pon en el PIN3 el valor del BIT3
  digitalWrite(4, bits[4]); 
  digitalWrite(5, bits[5]);
  digitalWrite(6, bits[6]);
 // digitalWrite(7, bits[7]);//pon en el PIN3 el valor del BIT7
 // delay(250);
 digitalWrite(7, 1); //A3
 delay(250);
  digitalWrite(7, 0);//A3
}
