/* 
 * File:   main.c
 * Author: Alan Cruz
 *
 * Created on 20 de septiembre de 2021, 12:26 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "LCD_lib.h"
#include "conf.h"

    char buffer1[3];

  float distancia = 2;
 int tiempo;



 void __interrupt() timer0(void){
     if(INTCONbits.TMR0IF){
                   TMR0 = 109;
                   distancia = distancia + 0.5;
                   INTCONbits.TMR0IF = 0;
     }
 }
 void confT0(){
 
      T0CONbits.TMR0ON = 1; //encendido
      T0CONbits.T08BIT = 1;  //modo 8 bits
      T0CONbits.T0CS = 0; //modo temporizador
      T0CONbits.T0SE = 1; //leer bajadas
      T0CONbits.PSA = 1;  //con preescalador
      T0CONbits.T0PS = 0b110; 
      
      INTCONbits.TMR0IE = 1;      // Habilitamos las interrupción por desborde de TIMER0
      INTCONbits.GIE = 1;         // Habilitamos las interrupciones globales
 }
 



/*
 * 
 */
int main(int argc, char** argv) {
    ADCON1 = 15;
    int count;

    TRISA = 0b00010000;
    
    confT0();

    //tiempo = 1/entrada*preescaador(255-TMR0)

    LCD_Init();
 

   

  while (1) { 
        
     distancia = 2;

        PORTAbits.RA5 = 1;
      __delay_us(10);
       PORTAbits.RA5 = 0;
     
       
          while(!PORTAbits.RA4);
          TMR0 = 109;
          T0CONbits.TMR0ON = 1;   

       
       while(PORTAbits.RA4);
        T0CONbits.TMR0ON = 0;   
        
  
        sprintf(buffer1,"%f",distancia);  //Texto alineado a la izquierda

        
        LCD_XY(0,0);
        LCD_Cadena("Distancia = ");
        LCD_XY(1,1);
        LCD_Cadena(buffer1);
        LCD_XY(1,9);
        LCD_Cadena("cm");
        __delay_ms(100);
    
  
     __delay_ms(60);
         

  
    

      
 	} 
 
 

    return (EXIT_SUCCESS);
    
    
    
    
}

