#include<LiquidCrystal.h> //Libreria para el LCD

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);//Inicializacion de la pantalla

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);//Se inicializa la pantalla
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp :");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    int dato = Serial.read();
    lcd.setCursor(7,0);
    lcd.print(dato);
    lcd.print("   ");
  }
}
