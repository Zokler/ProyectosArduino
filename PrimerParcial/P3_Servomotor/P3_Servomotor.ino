#include <Servo.h>
#include <Keypad.h>
#include <LiquidCrystal.h> 

const byte ROWS = 4; //N Filas
const byte COLS = 4; //N Filas
char keys[ROWS][COLS] = {
  {'1','2','3','a'},
  {'4','5','6','b'},
  {'7','8','9','c'},
  {'*','0','=','d'}
  };

byte rowPins[ROWS] = {38, 40, 42, 44};
byte colPins[COLS] = {46, 48, 50, 52};

String num;
int cont = 1,cont2=1 , comp;
int grado[15];
boolean flag = true, flag2 = true, flag3 = false;

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); //Inicializar KEYPAD

// Declaramos la variable para controlar el servo
Servo servoMotor;
 
void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Servomotor");
  delay (3000);
  lcd.clear();
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  servoMotor.attach(9);
}
 
void loop() {
  if(flag2 == true){iniciar();}
  if(flag3 == true){angulos();}
  
  
  
}

void motor(){

  for(int i = 1; i <= comp; i++)
  {
    servoMotor.write(grado[i]);
    delay(3000);
  }
}

void iniciar(){
  lcd.setCursor(0,0);
  lcd.print("Veces: ");
  char key = keypad.getKey();
  if (key != NO_KEY && (key=='1' || key=='2' || key=='3' || key=='4' || key=='5' || key=='6' || key=='7' || key=='8' || key=='9' || key=='0'))
  {
      num = num + key;
      int numLength = num.length();
      lcd.setCursor(15-numLength,0);
      lcd.print(num);
  }
  if (key !=NO_KEY && key == '=')
  {
    comp = num.toInt();
    flag2 = false;
    flag3 = true;
    num = "";
    lcd.setCursor(0,1);
    lcd.print(comp);
    lcd.clear();
  }
  if(key !=NO_KEY && key == '*')
  {
    lcd.clear();
    num = "";
    flag = true;
    comp = 0;
    cont = 1;
    cont2 = 1;

} 
} 

void angulos(){
  lcd.setCursor(0,0);
  lcd.print("Angulo ");
  lcd.print(cont2);
  lcd.print(": ");
  char key = keypad.getKey();
  if (key != NO_KEY && (key=='1' || key=='2' || key=='3' || key=='4' || key=='5' || key=='6' || key=='7' || key=='8' || key=='9' || key=='0'))
  {
      num = num + key;
      int numLength = num.length();
      lcd.setCursor(15-numLength,0);
      lcd.print(num);
  }
  if (key !=NO_KEY && key == '=')
  {
    if(cont == comp)
    {
      grado[cont] = num.toInt();
      flag = false;
    }
    
    if(flag == true)
    {
      grado[cont] = num.toInt();
      cont++;
      cont2++;
      num = "";
      lcd.setCursor(12,0);
      lcd.print("    ");
    }
    
    if(flag == false)
    {
      motor();
      flag3 = false;
    }
  }
  if(key !=NO_KEY && key == '*')
  {
    lcd.clear();
    num = "";
    flag = true;
    comp = 0;
    cont = 1;
    cont = 2;

}
  
}
