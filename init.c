#include <xc.h>
#include "config.h"
void init(void)
{
    /* turn off adc module and comparators*/
    ANSEL = 0x00;
    ANSELH = 0x00;  // ADC module off
    CM1CON0 = 0x00;
    CM2CON0 = 0x00; // comparators off
    
    /* internal clock setup*/
    OSCCONbits.IRCF2 = 1;           // 4 MHz clock configuration
    OSCCONbits.IRCF1 = 1;
    OSCCONbits.IRCF0 = 0;
    
    /* setup PORTB an PORTC pins as outputs*/
    TRISCbits.TRISC4 = 0;            // RC4 = RESET
    TRISCbits.TRISC0 = 0;            // RC0 = CS
    TRISCbits.TRISC3 = 0;            // RC3 = D/C
    TRISCbits.TRISC7 = 0;            // RC7 = MOSI
    TRISBbits.TRISB6 = 0;            // RB6 = SCK
    TRISBbits.TRISB4 = 0;            // RB4 = DIAGNOSTIC LED
    
    /* SPI setup where uController in Master mode, OLED display will be a slave
     SSPSTAT REG (sync serial port status register*/
    SSPSTATbits.SMP = 1;    // data sampled at end of output time
    SSPSTATbits.CKE = 0;    // data transmitted on falling edge of SCK, CKP = 0
    
    /* SSPCON REG (sync serial port control register*/
    SSPCONbits.WCOL = 0;    // cleared for no collision detection required
    SSPCONbits.SSPOV = 0;   // cleared for no overflow detection required
    SSPCONbits.SSPEN = 1;   // set to enable serial port pins SCK and SDO as serial port pins
    SSPCONbits.CKP = 1;     // set means idle state of clock is HIGH
    SSPCONbits.SSPM3 = 0;    // SPI master mode, clock = fosc/4
    SSPCONbits.SSPM2 = 0;
    SSPCONbits.SSPM1 = 0;
    SSPCONbits.SSPM0 = 0;
}
