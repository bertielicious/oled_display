#include <xc.h>
#include "config.h"
#include "config_oled.h"
#include "write_command.h"

void config_oled(void)
{
   CS = 0;             // select OLED chip (active LOW)
   RESET = 0;
   __delay_ms(1000);
   RESET = 1;
   __delay_ms(1000);
   write_command(SSD1306_DISPLAYOFF);             //0xAE  Set OLED Display Off
   write_command(SSD1306_SETDISPLAYCLOCKDIV);     //0xD5  Set Display Clock Divide Ratio/Oscillator Frequency
   write_command(0x80);                           // sets SSD1306 internal oscillator to it's value as if RESET
   write_command(SSD1306_SETMULTIPLEX);           //0xA8  Set Multiplex Ratio
   write_command(0x3f);                           //lines COM0 to COM63 for 128 x 64 display. 63 = 0x3f
   write_command(SSD1306_SETDISPLAYOFFSET);       //0xD3  Set Display Offset
   write_command(0x00);                           //affects the line characters are displayed
   write_command(SSD1306_SETSTARTLINE);           //0x40  Set Display Start Line
 
   write_command(SSD1306_CHARGEPUMP);             //0x8D  Set Charge Pump
   write_command(0x14);                           //0x14  Enable Charge Pump
   write_command(SSD1306_COMSCANDEC);             //0xC8  Set COM Output Scan Direction
   write_command(SSD1306_SETCOMPINS);             //0xDA  Set COM Pins Hardware Configuration
   write_command(0x12);
   write_command(SSD1306_SETCONTRAST);            //0x81   Set Contrast Control
   write_command(0xAF);
   write_command(SSD1306_SETPRECHARGE);           //0xD9   Set Pre-Charge Period
   write_command(0x25);
   write_command(SSD1306_SETVCOMDETECT);          //0xDB   Set VCOMH Deselect Level
   write_command(0x20);
   write_command(SSD1306_DISPLAYALLON_RESUME);    //0xA4   Set Entire Display On/Off
   write_command(SSD1306_NORMALDISPLAY);          //0xA6   Set Normal/Inverse Display
  // write_command(0xa7);
   write_command(0xA1);                           // mirror image of normal display selected
   //write_command(SSD1306_SET_COM_OUTPUT_SCAN_DIRECTION);
   write_command(SSD1306_DISPLAYON);              //0xAF   Set OLED Display On  
}

