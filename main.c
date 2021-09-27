/* 
 * File:   main.c
 * Author: Alan Cruz
 *
 * Created on 20 de septiembre de 2021, 12:26 PM
 */

#include <stdio.h>
#include <stdlib.h>



// PIC18F4550 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1L
#pragma config PLLDIV = 5       // PLL Prescaler Selection bits (Divide by 5 (20 MHz oscillator input))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 2       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes from the 96 MHz PLL divided by 2)

// CONFIG1H
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator (HS))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = ON         // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting 2.05V)
#pragma config VREGEN = OFF     // USB Voltage Regulator Enable bit (USB voltage regulator disabled)

// CONFIG2H
#pragma config WDT = ON         // Watchdog Timer Enable bit (WDT enabled)
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = ON      // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = ON      // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer 1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = ON         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
#pragma config ICPRT = OFF      // Dedicated In-Circuit Debug/Programming Port (ICPORT) Enable bit (ICPORT disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) is not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) is not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) is not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) is not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) is not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM is not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) is not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) is not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) is not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) is not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) are not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) is not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM is not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) is not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) is not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>




#define _XTAL_FREQ 20000000
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
 int distancia = 2;
 int tiempo;

 void display(int count){
    
    int n;
    int n1;
    
    n =  count;
    
   
    
    switch(n){
        case 0:
            PORTC = 0b10111111;
            break;
        case 1:
            PORTC = 0b00000110;
            break;

        case 2:
            PORTC = 0b11011011;
            break;
            
        case 3:
            PORTC = 0b11001111;
            break;
            
        case 4:
            PORTC = 0b01100110;
            break;
        case 5:
            PORTC = 0b11101101;
            break;
        case 6:
            PORTC = 0b11111101;
            break;
        case 7:
            PORTC = 0b00000111;
            break;
        case 8:
            PORTC = 0b11111111;
            break;
         case 9:
            PORTC = 0b11101111;
            break;
        default: break;
            
       
    }
         
    switch(n){
        case 0:
            PORTD = 0b10111111;
            break;
        case 1:
            PORTD = 0b00000110;
            break;

        case 2:
            PORTD = 0b11011011;
            break;
            
        case 3:
            PORTD = 0b11001111;
            break;
            
        case 4:
            PORTD = 0b01100110;
            break;
        case 5:
            PORTD = 0b11101101;
            break;
        case 6:
            PORTD = 0b11111101;
            break;
        case 7:
            PORTD = 0b00000111;
            break;
        case 8:
            PORTD = 0b11111111;
            break;
         case 9:
            PORTD = 0b11101111;
            break;
        default: 
            
                        PORTD = 0b11111111;

            break;
            
       
    }

    return;  
    
}
 
 void __interrupt() timer0(void){
     if(INTCONbits.TMR0IF){
                   TMR0 = 109;
                   distancia++;
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
    TRISC = 0;
    TRISD = 0;
    TRISA = 0b00010000;
    
    confT0();

    //tiempo = 1/entrada*preescaador(255-TMR0)


 
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

  
      display(distancia);
     __delay_ms(60);
         

  
    

      
 	} 
 
 

    return (EXIT_SUCCESS);
    
    
    
    
}

