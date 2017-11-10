#include "config.h"
#include "send_spi_byte.h"
void write_data(uchar data)
{
    CS = 0;
    DC = 1;
    send_spi_byte(data);
    CS = 1;
}


