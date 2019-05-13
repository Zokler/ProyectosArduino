#line 1 "C:/Users/Cesar Escalante/Documents/CETI/7mo. semestre/Sistemas embebidos/Practicas SE1/Practica7/Practica7.c"
unsigned int temp_res, temp;
char txt;
void main() {
 TRISA = 0xFF;
 ADC_Init();
 UART1_Init(9600);
 UART1_Write_Text("Start");
 UART1_Write(10);
 UART1_Write(13);

 while(1){
 temp_res = ADC_Read(0);
 temp=Bcd2Dec16(temp_res);
 UART1_Write(temp);
 delay_ms(1000);
 }
}
