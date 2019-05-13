
_main:

;Practica7.c,3 :: 		void main() {
;Practica7.c,4 :: 		TRISA  = 0xFF;              // PORTA is input
	MOVLW      255
	MOVWF      TRISA+0
;Practica7.c,5 :: 		ADC_Init();
	CALL       _ADC_Init+0
;Practica7.c,6 :: 		UART1_Init(9600);
	MOVLW      77
	MOVWF      SPBRG+0
	BSF        TXSTA+0, 2
	CALL       _UART1_Init+0
;Practica7.c,7 :: 		UART1_Write_Text("Start");
	MOVLW      ?lstr1_Practica7+0
	MOVWF      FARG_UART1_Write_Text_uart_text+0
	CALL       _UART1_Write_Text+0
;Practica7.c,8 :: 		UART1_Write(10);
	MOVLW      10
	MOVWF      FARG_UART1_Write_data_+0
	CALL       _UART1_Write+0
;Practica7.c,9 :: 		UART1_Write(13);
	MOVLW      13
	MOVWF      FARG_UART1_Write_data_+0
	CALL       _UART1_Write+0
;Practica7.c,11 :: 		while(1){
L_main0:
;Practica7.c,12 :: 		temp_res = ADC_Read(0);   // Get 10-bit results of AD conversion
	CLRF       FARG_ADC_Read_channel+0
	CALL       _ADC_Read+0
	MOVF       R0+0, 0
	MOVWF      _temp_res+0
	MOVF       R0+1, 0
	MOVWF      _temp_res+1
;Practica7.c,13 :: 		temp=Bcd2Dec16(temp_res);
	MOVF       R0+0, 0
	MOVWF      FARG_Bcd2Dec16_bcdnum+0
	MOVF       R0+1, 0
	MOVWF      FARG_Bcd2Dec16_bcdnum+1
	CALL       _Bcd2Dec16+0
	MOVF       R0+0, 0
	MOVWF      _temp+0
	MOVF       R0+1, 0
	MOVWF      _temp+1
;Practica7.c,14 :: 		UART1_Write(temp);       // and send data via UART
	MOVF       R0+0, 0
	MOVWF      FARG_UART1_Write_data_+0
	CALL       _UART1_Write+0
;Practica7.c,15 :: 		delay_ms(1000);
	MOVLW      16
	MOVWF      R11+0
	MOVLW      57
	MOVWF      R12+0
	MOVLW      13
	MOVWF      R13+0
L_main2:
	DECFSZ     R13+0, 1
	GOTO       L_main2
	DECFSZ     R12+0, 1
	GOTO       L_main2
	DECFSZ     R11+0, 1
	GOTO       L_main2
	NOP
	NOP
;Practica7.c,16 :: 		}
	GOTO       L_main0
;Practica7.c,17 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
