#include <LiquidCrystal.h>
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
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

byte fPins[filas] = {14, 15, 16, 17};//Pines de conexion de las filas
byte cPins[colums] = {18, 19, 20, 21};//Pines de conexion de las columnas



//Inicializacion del teclado
Keypad keypad = Keypad(makeKeymap(keys), fPins, cPins, filas, colums);
char key = NULL;
const int RF= 2;//Pin de conexion

void setup(){
  lcd.begin(16, 2);
  lcd.clear();
  lcd.home();
  lcd.print("BOOM");
  Serial.begin(9600);
  delay(500);
}

void loop(){
  key = keypad.getKey();
    if(key!= NO_KEY){
      lcd.clear();
      char data[1];
      data[0]=key;
      
      Serial.write(key);
      lcd.print(key);
      
    }
    delay(200);
}
