#include <xc.h>
#include "config.h"
void config_adc(void)
{
    
    TRISCbits.TRISC1 = 1;       // analogue input
    ANSELbits.ANS5 = 1;         // ANS5 is an analogue input (pin 15))
    ADCON0bits.CHS3 = 0;        // channel 5 selected to send to ADC
    ADCON0bits.CHS2 = 1;
    ADCON0bits.CHS1 = 0;
    ADCON0bits.CHS0 = 1;
    ADCON0bits.VCFG = 0;        // onboard voltage reference is voltage reference for ADC (+5v)
    ADCON0bits.ADFM = 1;        // 10 bit ADC result is right justified
    ADCON1bits.ADCS2 = 1;       // assuming 4MHz clock, 11 TAD periods  = fosc/16
    ADCON1bits.ADCS1 = 0;
    ADCON1bits.ADCS0 = 1;
    
    ADCON0bits.ADFM = 1;
    ADCON0bits.ADON = 1;        // ADC is enabled
   
}
