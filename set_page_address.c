#include <xc.h>
#include "config.h"
#include "write_command.h"
void set_page_address(uchar add)
{
    add = 0xb0|add;
    write_command(add);
}
