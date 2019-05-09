#include <VirtualWire.h>
#include<LiquidCrystal.h> //Libreria para el LCD

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);//Inicializacion de la pantalla

const int IN4 = 7;
const int IN3 = 6;
const int ENB = 5;
const int RF= 2;//Pin de conexion

void setup() {
  // Se inicializa el RF
  vw_setup(2000);  // velocidad: Bits per segundo
  vw_set_rx_pin(RF);  //Pin como entrada del RF
  vw_rx_start();       // Se inicia como receptor

  //Asignacion de pines de control para motor
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  //Asignacion valores iniciales a los pines
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 100);

  lcd.begin(16, 2);//Se inicializa la pantalla
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Dato :");
}

void loop(){
  uint8_t dato;
  uint8_t datoleng = 1;
  
  //verificamos si hay un dato valido en el RF
  if (vw_get_message(&dato, &datoleng)){
    lcd.setCursor(0,0);
    lcd.print("Dato :");
    lcd.print((char)dato);
    
    if ((char)dato == '0'){//Motor apagado
      analogWrite(ENB, 0);
      lcd.setCursor(0,1);
      lcd.print("Motor apagado");
    }
    else if ((char)dato == 'A'){//Velocidad 1
      analogWrite(ENB, 85);
      lcd.setCursor(0,1);
      lcd.print("Velocidad 1  ");
    }
    else if ((char)dato == '4'){//Velocidad 2
      analogWrite(ENB, 170);
      lcd.setCursor(0,1);
      lcd.print("Velocidad 2  ");
    }
    else if((char)dato == 'B'){//Velocidad 3
      analogWrite(ENB,255 );
      lcd.setCursor(0,1);
      lcd.print("Velocidad 3  ");
    }
    else {
      lcd.setCursor(0,1);
      lcd.print("             ");
    }
  }
}
