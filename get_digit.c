#include <xc.h>
#include "config.h"
#include "write_chracter.h"
void get_digit(uchar num, uchar shuffle)
{
    
    switch (num)
    {
        case 0:
            write_character(&zero_sixteen_times_sixteen[0],shuffle, 0xb2);
            break;
        case 1:
            write_character(&one_sixteen_times_sixteen[0],shuffle, 0xb2);
            break;
        case 2:
            write_character(&two_sixteen_times_sixteen[0],shuffle, 0xb2);
            break;
        case 3:
            write_character(&three_sixteen_times_sixteen[0],shuffle,0xb2);
            break;
        case 4:
            write_character(&four_sixteen_times_sixteen[0],shuffle, 0xb2);
            break;
        case 5:
           write_character(&five_sixteen_times_sixteen[0],shuffle, 0xb2);
            break;
        case 6:
             write_character(&six_sixteen_times_sixteen[0],shuffle, 0xb2);
            break;
        case 7:
            write_character(&seven_sixteen_times_sixteen[0],shuffle, 0xb2);
            break;
        case 8:
            write_character(&eight_sixteen_times_sixteen[0],shuffle, 0xb2);
            break;
        case 9:
            write_character(&nine_sixteen_times_sixteen[0],shuffle, 0xb2);
            break;
        
            
        default:
            break;
    }
}
