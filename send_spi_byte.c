#include <xc.h>
#include "config.h"
#include "send_spi_byte.h"
void send_spi_byte(uchar byte)
{
    SSPBUF = byte;  // send byte MSB first
    while(SSPSTATbits.BF != 1)
    {
        ; // wait for all 8 bits to be transmitted
    }
}
