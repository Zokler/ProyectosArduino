unsigned int temp_res, temp;
char txt;
void main() {
  TRISA  = 0xFF;              // PORTA is input
  ADC_Init();
  UART1_Init(9600);
  UART1_Write_Text("Start");
  UART1_Write(10);
  UART1_Write(13);

  while(1){
    temp_res = ADC_Read(0);   // Get 10-bit results of AD conversion
    temp=Bcd2Dec16(temp_res);
    UART1_Write(temp);       // and send data via UART
    delay_ms(1000);
  }
}