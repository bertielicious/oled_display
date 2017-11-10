#include "config.h"
#include "init.h"
#include "write_command.h"
#include "write_data.h"
#include "config_adc.h"
#include "config_oled.h"
#include "clear_oled.h"
#include "set_page.h"
#include "set_columns.h"
#include "split_digit.h"
#include "get_digit.h"
#include "write_chracter.h"
int main(void)
{
    uchar inc, offset, offset1, offset2 = 0;
    float celcius = 0;
    init();
    config_adc();
    CS = 0;             // SSD1306 OLED selected/ active
    config_oled();
    clear_oled();
    inc = write_character(&T[0],0,0xb0);  
    offset = write_character(&e[0],inc, 0xb0);  
    offset1 = write_character(&m[0],offset + inc, 0xb0);  
    offset2 = write_character(&p[0],offset + inc + offset1,0xb0);  
    while(1)
    {   
        celcius = adc_conversion();// function returns a 10-bit result of temp conversion in Celcius to variable celius
        split_digit(celcius);
        set_page(0x20,0x10,0xb2);
        set_columns(0x21,0x00,0x0f);
        get_digit(thou,0x00);
        set_page(0x20,0x10,0xb2);
        set_columns(0x21,0x10,0x1f);
        get_digit(hun, 0x0f);
        set_page(0x20,0x10,0xb2);
        set_columns(0x21,0x20,0x2f);
        get_digit(ten,0x1f);
        set_page(0x20,0x10, 0xb2);
        set_columns(0x21,0x30,0x3f);
        write_character(&decimal_point[0], 0x30,0xb2);
        set_page(0x20,0x10,0xb2);
        set_columns(0x21,0x40,0x4f);
        get_digit(unit, 0x3f);
        set_page(0x20,0x10,0xb2);
        set_columns(0x21,0x50,0x5f);
        write_character(&deg[0],0x50,0xb2);
        set_columns(0x21,0x60, 0x6f);
        write_character(&C[0],0x60,0xb2);
        __delay_ms(1000);  
    }
            
}
