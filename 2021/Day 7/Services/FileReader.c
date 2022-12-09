#include "./FileReader.h"

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

char* readFile(char *fileName){
    
    FILE *fp;
    fp = fopen(fileName, "rb");
    
    if (fp == NULL){
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    
    fseek(fp, 0L, SEEK_END);
    
    int64_t fsize = ftell(fp);
    
    fseek(fp, 0L, SEEK_SET);

    char *contents = malloc((fsize+1) * sizeof(char));
    char *p = contents;
    
    uint32_t i = 0;
    for (; (*(p+i) = fgetc(fp)) != EOF; i++);
    
    *(p+i) = '\0';
    
    return contents;
}
