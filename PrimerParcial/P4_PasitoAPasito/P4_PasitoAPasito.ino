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
//------------------------------------------------------------------------------------
char tecla;
int contadorDeDigitos = 0;
String vecesEnString;
int vecesEnInt;

void setup() {
    pinMode(18, OUTPUT);    // Pin 18 conectar a IN4
    pinMode(19, OUTPUT);    // Pin 19 conectar a IN3
    pinMode(20, OUTPUT);     // Pin 20 conectar a IN2
    pinMode(21, OUTPUT);     // Pin 21 conectar a IN1
    
    lcd.begin(16,2);
    lcd.home();
    lcd.print("Digit veces: ");

}

void loop() {
esCero:
  tecla = myKeypad.waitForKey();
  
  if(tecla == '1' || tecla == '2' || tecla == '3' || tecla == '4' || tecla == '5' || tecla == '6' || tecla == '7' || tecla == '8' || tecla == '9' || tecla == '0'
  && contadorDeDigitos < 2)
  {
      vecesEnString = vecesEnString + tecla;
      int numLength = vecesEnString.length();
      lcd.setCursor(15-numLength,1);
      lcd.print(vecesEnString);
      contadorDeDigitos++;
  }
 //------------------------------------------------------------------------------------------------------------------------------------------------------------------ 
  if(tecla == '*' && contadorDeDigitos >= 1)
  {
      vecesEnInt = vecesEnString.toInt();
      if (vecesEnInt == 0) //protección en caso de que se haya presionado 0 solamente
      {
        contadorDeDigitos--;
        goto esCero;
      }

      iniciarSecuencia(vecesEnInt);
      
  }
  //------------------------------------------------------------------------------------------------------------------------------------------------------------------
  if(tecla == '#')
  {
      reboot();
  }
  
}

    void iniciarSecuencia(int vecesRecibidas)
    {
        int secuencia[vecesRecibidas];
        char teclaDeSecuencia;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("1-Der 2-Izq 3-Pa");
       
        for(int contadorDeSecuencia = 1; contadorDeSecuencia <= vecesRecibidas; contadorDeSecuencia++)
        {
              noFueNumeroValido:
              lcd.setCursor(0,1);
              teclaDeSecuencia = myKeypad.waitForKey();
              
              switch(teclaDeSecuencia)
              {
                case '1':
                secuencia[contadorDeSecuencia] = 1;
                break;

                case '2':
                secuencia[contadorDeSecuencia] = 2;
                break;

                case '3':
                secuencia[contadorDeSecuencia] = 3;
                break;

                default:
                lcd.print("no valido");
                delay(1000);
                lcd.clear();
                lcd.print("1-Der 2-Izq 3-Pa");
                goto noFueNumeroValido;
                break;
              }
        }//FIN FOR CONTADORDESECUENCIA

        for(int girarMotor = 1; girarMotor <= vecesRecibidas; girarMotor++)
        {
          if(secuencia[girarMotor]==1)
          {
              lcd.clear();
              lcd.print("izquierda");
              paso_izq();

          }
          if(secuencia[girarMotor]==2)
          {
              lcd.clear();
              lcd.print("derecha");
              paso_der();

          } 
        }//FIN FOR GIRARMOTOR
        reboot();
    }//FIN FUNCION
void reboot()
{
     contadorDeDigitos = 0;
     vecesEnString = ' ';
     vecesEnInt = 0;
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
}
void paso_der(){         // Pasos a la derecha
 digitalWrite(18, LOW); 
 digitalWrite(19, LOW);  
 digitalWrite(20, HIGH);  
 digitalWrite(21, HIGH);  
   delay(retardo); 
 digitalWrite(18, LOW); 
 digitalWrite(19, HIGH);  
 digitalWrite(20, HIGH);  
 digitalWrite(21, LOW);  
   delay(retardo); 
 digitalWrite(18, HIGH); 
 digitalWrite(19, HIGH);  
 digitalWrite(20, LOW);  
 digitalWrite(21, LOW);  
  delay(retardo); 
 digitalWrite(18, HIGH); 
 digitalWrite(19, LOW);  
 digitalWrite(20, LOW);  
 digitalWrite(21, HIGH);  
  delay(retardo);  
}

void paso_izq() {        // Pasos a la izquierda
 digitalWrite(18, HIGH); 
 digitalWrite(19, HIGH);  
 digitalWrite(20, LOW);  
 digitalWrite(21, LOW);  
  delay(retardo); 
 digitalWrite(18, LOW); 
 digitalWrite(19, HIGH);  
 digitalWrite(20, HIGH);  
 digitalWrite(21, LOW);  
  delay(retardo); 
 digitalWrite(18, LOW); 
 digitalWrite(19, LOW);  
 digitalWrite(20, HIGH);  
 digitalWrite(21, HIGH);  
  delay(retardo); 
 digitalWrite(18, HIGH); 
 digitalWrite(19, LOW);  
 digitalWrite(20, LOW);  
 digitalWrite(21, HIGH);  
  delay(retardo); 
}
        
void apagado() {         // Apagado del Motor
 digitalWrite(18, LOW); 
 digitalWrite(19, LOW);  
 digitalWrite(20, LOW);  
 digitalWrite(21, LOW);  
 }
