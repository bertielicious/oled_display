#include <xc.h>
#include "config.h"
#include "split_digit.h"
void split_digit(int number)
{
    thou = number/1000;
    hun = number/100;
    ten =  (number/10)%10;
    unit = number%10;
}
