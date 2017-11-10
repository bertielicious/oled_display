#include "config.h"
#include "send_spi_byte.h"
void write_command (char comd)
{
    CS = 0;
    DC = 0;
    send_spi_byte(comd);
    CS = 1;
}
