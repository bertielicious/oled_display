#include <pic16f690.h>
#include <xc.h>
#include "config.h"
 int adc_conversion(void)
{
    unsigned int ten_bit_val = 0x0000;   // int will hold the 10 bit result of ad conversion
    uchar low_eight_adc_val = 0x00;    // create an 8 bit variable to hold ADRESL
    uchar high_two_adc_val = 0x00;     // create an 8 bit variable to hold ADRESH
     
    if(ADCON0bits.GO_DONE == 0)// if go_done = 0
    {
        ADCON0bits.GO_DONE = 1;  // set GO_DONE to start a conversion
    }
        while(ADCON0bits.GO_DONE == 1) // while go_done = 1
        {
            ;                       // wait for conversion to finish
        }
    
    low_eight_adc_val = ADRESL;
    high_two_adc_val = ADRESH;    
    
    ten_bit_val = (high_two_adc_val << 8) + low_eight_adc_val;  //combine high and low byte ADC values to make a 10 bit ADC result
    ten_bit_val = (float)(ten_bit_val * 5.0);
    return ten_bit_val;
}
