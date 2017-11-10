#include "config.h"
#include "write_command.h"

void set_page(uchar memory_mode, uchar page_mode, uchar page_addr)
{
    write_command(memory_mode);    // set memory addressing mode
    write_command(page_mode);    // enter page addressing mode
    write_command(page_addr);    // set page address to page 0
}
