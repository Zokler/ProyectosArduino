#include <LiquidCrystal.h>
LiquidCrystal lcd(48, 46, 44, 42, 40, 38);
#include <Keypad.h>
const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad
char keymap[numRows][numCols]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'A'}, 
{'7', '8', '9', 'A'},
{'*', '0', '#', 'A'}
};
byte rowPins[numRows] = {22,24,26,28}; 
byte colPins[numCols]= {30,32,34,36}; //A0, A1 PARA ARDUINO UNO
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
//-------------------------------------------------------------------------------;

char tecla;
int contadorDeDigitos = 0;
String segundosEnString;
double segundosEnInt;
double segundosToMilisegundos;

//variables motores:
int in1 = 8; //pin 8
int in2 = 9; //pin 9
int enA = 10; //pin 10

void setup() {
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(enA, OUTPUT);
    
    lcd.begin(16,2);
    lcd.home();
    lcd.print("Digit sec: ");
}

void loop() {
  esCero:
  tecla = myKeypad.waitForKey();
  
  if(tecla == '1' || tecla == '2' || tecla == '3' || tecla == '4' || tecla == '5' || tecla == '6' || tecla == '7' || tecla == '8' || tecla == '9' || tecla == '0'
  && contadorDeDigitos<2)
  {
      segundosEnString = segundosEnString + tecla;
      int numLength = segundosEnString.length();
      lcd.setCursor(15-numLength,1);
      lcd.print(segundosEnString);
      contadorDeDigitos++;
  }
 //------------------------------------------------------------------------------------------------------------------------------------------------------------------ 
  if(tecla == '*' && contadorDeDigitos >= 1)
  {
      segundosEnInt = segundosEnString.toInt();
      if (segundosEnInt == 0)//protección en caso de que se haya presionado 0 solamente, si lo es regresa a que ingrese un dato
      {
        contadorDeDigitos--;
        goto esCero;
      }
      segundosToMilisegundos = segundosEnInt * 1000;
      funcionDeAvance(segundosToMilisegundos);
  }
  //------------------------------------------------------------------------------------------------------------------------------------------------------------------
  if(tecla == '#')
  {
      reboot();
  }
  
}
void funcionDeAvance(double segundosRecibidos)
{

  double terciaDeSegundos = (segundosRecibidos/3);
  double cuartoDeSegundos = (terciaDeSegundos/4); //cuarta parte de la primer tercera parte
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Aumentando");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); //combinacion para avanzar

  analogWrite(enA, 63);
  delay(cuartoDeSegundos);
  analogWrite(enA, 126);
  delay(cuartoDeSegundos);
  analogWrite(enA, 189);
  delay(cuartoDeSegundos);
  analogWrite(enA, 255);

  lcd.clear();
  lcd.print("Tope");
  delay(terciaDeSegundos);

  lcd.clear();
  lcd.print("Disminuyendo");
  analogWrite(enA, 255);
  delay(cuartoDeSegundos);
  analogWrite(enA, 189);
  delay(cuartoDeSegundos);
  analogWrite(enA, 126);
  delay(cuartoDeSegundos);
  analogWrite(enA, 63);
  delay(cuartoDeSegundos);
 reboot();
  
}
void reboot()
{
      contadorDeDigitos = 0;
      segundosEnString = ' ';
      segundosEnInt = 0;
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      lcd.clear();
      lcd.print("Digit sec: ");
      
}
/*
 *  avanzar:
 *  in1 low
 *  in2 high
 *  
 *  cambio de sentido:
 *  in1 high
 *  in2 low
 *  
 *  detener:
 *  in1 low
 *  in2 low

 */
