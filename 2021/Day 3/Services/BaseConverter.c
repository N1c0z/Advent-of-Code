#include "BaseConverter.h"
#include <inttypes.h>
uint64_t binaryToDecimal(uint64_t n)
{
    uint64_t num = n;
    uint64_t result = 0;
 
    uint64_t base = 1;
 
    uint64_t temp = num;
    while (temp) {
        uint64_t lastDigit = temp % 10;
        temp = temp / 10;
 
        result += lastDigit * base;
 
        base = base * 2;
    }
 
    return result;
}
