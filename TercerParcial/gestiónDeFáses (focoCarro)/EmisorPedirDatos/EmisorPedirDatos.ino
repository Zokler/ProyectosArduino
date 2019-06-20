#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

//Codigo necesario para leer teclado
const byte filas = 4;
const byte columnas = 4;

byte pinesFilas[filas] = {14, 15, 16, 17};
byte pinesColumnas[columnas] = {18, 19, 20, 21};

char matrizTeclado[filas][columnas] = {
  {'1', '2', '3', ' '},
  {'4', '5', '6', ' '},
  {'7', '8', '9', ' '},
  {'*', '0', '#', ' '}
};

Keypad teclado = Keypad(makeKeymap(matrizTeclado), pinesFilas, pinesColumnas, filas, columnas);
//Codigo necesario para leer teclado

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.home();
  lcd.print("BOOM");
  Serial.begin(9600);
  delay(500);
}

void loop() {
    lcd.clear();
  char tecla = teclado.getKey();
  while(tecla != '*'){    
      lcd.print("Nivel:");
      lcd.setCursor(0, 1);
      int potencia = obtenerNumero();
      lcd.clear();
      Serial.write(potencia);
  }
}

int obtenerNumero() {
  int num = 0;
  char tecla = teclado.waitForKey();
  while (tecla != '#') {
    switch (tecla) {
      case '1':
        num = 1;
        lcd.print(tecla);
        break;
      case '2':
        num = 2;
        lcd.print(tecla);
        break;
      case '3': 
        num = 3;
        lcd.print(tecla);
        break;
      case '4':
        num = 4;
        lcd.print(tecla);
        break;
    
    }
    tecla = teclado.getKey();
  }
  return num;
}
