#include "Services/FileReader.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>

//char** split(char delimeter, char* str);
char** str_split(char* a_str, const char a_delim);
int main(void){
    char filename[] = "/Users/nico/Documents/Code stuff/AdventOfCode/Inputs/12.txt";
    char *contents = readFile(filename);
}