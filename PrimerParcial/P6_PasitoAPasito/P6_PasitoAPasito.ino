#include <LiquidCrystal.h>
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);
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
int Steps = 0;
int veces=100;
boolean Direction = true; 

#define IN1  12
#define IN2  11
#define IN3  10
#define IN4  9

int Paso [ 8 ][ 4 ] = //array de motor a pasos usando medios pasos
    {   {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1},
        {1, 0, 0, 1}
     };
     
void setup() {
      pinMode(IN1, OUTPUT); 
      pinMode(IN2, OUTPUT); 
      pinMode(IN3, OUTPUT); 
      pinMode(IN4, OUTPUT); 
    
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
  
}//fin loop

    void iniciarSecuencia(int vecesRecibidas)
    {   
        int Veces=0;
        int secuencia[vecesRecibidas*100];
        char teclaDeSecuencia;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("1-Der 2-Izq");
       
        for(int contadorDeSecuencia = 1; contadorDeSecuencia <= vecesRecibidas; contadorDeSecuencia++)
        {
              noFueNumeroValido:
              lcd.setCursor(0,1);
              teclaDeSecuencia = myKeypad.waitForKey();
              
              switch(teclaDeSecuencia)
              {
                case '1':
               for(int i=0; i<100; i++)
               {
                  secuencia[Veces] = 1;
                  Veces++;
               }
                break;

                case '2':
                for(int i=0; i<100; i++)
               {
                  secuencia[Veces] = 2;
                  Veces++;
               }
                break;
                
                default:
                lcd.print("no valido");
                delay(1000);
                lcd.clear();
                lcd.print("1-Der 2-Izq");
                goto noFueNumeroValido;
                break;
              }
        }//FIN FOR CONTADORDESECUENCIA

        for(int girarMotor = 1; girarMotor <= vecesRecibidas*100; girarMotor++)
        { 
          if(secuencia[girarMotor]==1)
          {
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("Paso: ");
              lcd.print(girarMotor);
              lcd.setCursor(0,1);
              lcd.print("Derecha");
              Direction = true;
              for(int i=0; i<=7; i++){
                stepper();
                delay(5);
              }
              

          }
          if(secuencia[girarMotor]==2)
          {
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("Paso: ");
              lcd.print(girarMotor);
              lcd.setCursor(0,1);
              lcd.print("Izquierda");
              Direction = false;
              for(int i=0; i<=7; i++){
                stepper();
                delay(5);
              }

          } 
          veces++;
        }//FIN FOR GIRARMOTOR
        reboot();
    }//FIN FUNCION
void reboot()
{
     contadorDeDigitos = 0;
     vecesEnString = ' ';
     vecesEnInt = 0;
     Steps = 0;
     Direction = true;   
}
void stepper()            //Avanza un paso
{
  
  digitalWrite( IN1, Paso[Steps][ 0] );
  digitalWrite( IN2, Paso[Steps][ 1] );
  digitalWrite( IN3, Paso[Steps][ 2] );
  digitalWrite( IN4, Paso[Steps][ 3] );
  SetDirection();
}

void SetDirection()
{
    if(Direction)
        Steps++;
    else 
        Steps--; 
     
    Steps = ( Steps + 7 ) % 7 ;
/*    if (Steps>7)
      Steps=0 ;
      if (Steps<0)
      Steps=7 ;
    */
}
