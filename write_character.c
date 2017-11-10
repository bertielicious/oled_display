#include "config.h"
#include "write_data.h"
#include "set_page.h"
#include "set_columns.h"
uchar write_character(uchar *ptr, uchar inc, uchar page)
{
    uchar x = 0;
    
        set_page(0x20, 0x10, page);     // set_page(set_memory_mode, page_addressing_mode, page_address
        //          0x20 = memory mode, 0x00 = horizontal, 0x01 = vertical, 0x10 = page, page address = 0xb0 -> 0xb7
        
        set_columns(0x21, 0x00 + inc, 0x07 + inc);  // set_columns(set column address,col start address (0->d'127), col end address (0->d'127))
        //we now write a 16x16 character by writing four 8x8 quadrants of the character 1 | 2
        //                                                                              3 | 4
        for(x = 0; x < 8; x ++)
        {
            write_data(*ptr);   //write quadrant 1 to oled display  1 | 2
            ptr = ptr + 1;      //                                  3 | 4
        }
        set_page(0x20, 0x10, page);
        set_columns(0x21, 0x08 + inc, 0x15 + inc);
        for(x = 8; x < 16; x ++)
        {
            write_data(*ptr);   //  write quadrant 2 to oled display  1 | 2
            ptr = ptr + 1;          //                                3 | 4
        }
        set_page(0x20, 0x10, page+1);
        set_columns(0x21, 0x00 + inc, 0x07 + inc);
        for(x = 16; x < 24; x ++)
        {
            write_data(*ptr);//  write quadrant 3 to oled display  1 | 2
            ptr = ptr + 1;          //                             3 | 4
        }
        
        set_page(0x20, 0x10, page+1);
        set_columns(0x21, 0x08 + inc, 0x15 + inc);
        for(x = 24; x < 32; x ++)
        {
            write_data(*ptr);   //  write quadrant 4 to oled display  1 | 2
            ptr = ptr + 1;             //                             3 | 4
        }
        return x - 12;              // determines spacing between characters
}