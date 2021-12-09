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
    char filename[] = "/Users/nico/Documents/Code stuff/AdventOfCode/Inputs/07.txt";
    char *contents = readFile(filename);
    char** contentsArray = str_split(contents, ',');
    

    int amountOfTries  = 1000;
    int* sumOfDelta = malloc(sizeof(int) * amountOfTries);
    for (int i = 0; i < amountOfTries; i++) {
        *(sumOfDelta+i) = 0;
        for (int k = 0; *(contentsArray+k); k++) {

            *(sumOfDelta+i) += abs(atoi(*(contentsArray+k))-i);
        }
        printf("\n");
    }
    int lowestI = 0;
    for (int i = 0; i < amountOfTries; i++) {
        if (*(lowestI+sumOfDelta) > *(sumOfDelta+i)) {
            lowestI = i;
        }
    }
    printf("%d\n%d", *(sumOfDelta+lowestI), lowestI);
    return 0;
}

// still dont understand why this no work ;c
//char** split(char delimeter, char* str){
//    char **result = malloc(sizeof(char));
//    int sizeOfStr = 0;
//    char* p = str;
//    int sizeOfResult = 0;
//    while (*(p+sizeOfStr)) {
//        sizeOfStr++;
//    }
//    int startChar = 0, endChar = 0;
//    p = str;
//
//    while (*p) {
//        endChar++;
//
//        if (*p == delimeter || (!*(p+1))) {
//            endChar  = (*(p+1) == '\0') * (sizeOfStr+1) + (*(p+1) != '\0') * endChar;
//            sizeOfResult++;
//            result = realloc(result, sizeOfResult * sizeof(char*));
//
//            if(!result){
//                printf("Error using realloc");
//                exit(EXIT_FAILURE);
//            }
//            char* tempStr = malloc((endChar-startChar+1)*sizeof(char));
//
//            if(!tempStr){
//                printf("Error using malloc");
//                exit(EXIT_FAILURE);
//            }
//            char* q = tempStr;
//            for (int i = startChar; i < endChar-1; i++) {
//                *q++ = str[i];
//            }
//            startChar = endChar;
//            *q = '\0';
//            *(result+sizeOfResult-1) = tempStr;
//        }
//        p++;
//    }
//    *(result+sizeOfResult) = NULL;
//
//    for (int i = 0; *(result+i) != NULL; i++) {
//        for (int k = 0 ; *(*(result+i)+k) != '\0'; k++) {
//            printf("%c", *(*(result+i)+k));
//        }
//        printf("\n");
//    }
//    return result;
//}
char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    count += last_comma < (a_str + strlen(a_str) - 1);

    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}