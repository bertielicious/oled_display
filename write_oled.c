#include <xc.h>
#include "config.h"
#include "config_oled.h"
#include "write_data.h"
void write_oled(uchar *almunecar)
{
   uchar i = 0;
   uchar result[8];
   uchar h = 0;
   for(i = 0; i < 8; i++)
   {
       result[i] = *almunecar;
       almunecar++;
       h = result[i];
       write_data(h);
   }
    
}
