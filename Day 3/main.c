#include "Services/FileReader.h"
#include "Services/BaseConverter.h"

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>


int main(void){
    char filename[] = "/Inputs/03.txt";
    char *contents = readFile(filename);
    char* p = contents;
    int columnSize = 1;
    int rowAmount = 1; //this is one bc no \n on last line bc we have \0
    uint32_t amountOfOnes = 0;
    uint32_t amountOfZeros = 0;
    uint64_t num = 0;
    uint64_t num1 = 0;
    
    for (size_t i = 0; contents[i]; i++) rowAmount += (contents[i] == '\n');
    
    for (; contents[columnSize-1] != '\n'; columnSize++);

    for (size_t i = 0; i < columnSize-1; i++)
    {
        for (size_t k = 0; k < rowAmount; k++){
            amountOfOnes += *(p+k*columnSize + i) - '0';
        }

        if (amountOfOnes > (rowAmount/2))
        {
            num = num * 10;
            num += 1;
            num1 = num1 * 10;
        }
        else
        {
            num1 = num1 * 10;
            num1 += 1;
            num = num * 10;
        }
        amountOfZeros = 0;
        amountOfOnes = 0;
    }
    
    printf("Result: %llu\n", binaryToDecimal(num) * binaryToDecimal(num1));
    return 0;
}
