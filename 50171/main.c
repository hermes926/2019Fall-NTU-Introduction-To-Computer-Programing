
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "splitAndMap.h"
#define numPtrArray 4
#define MAXLEN 400000
int main(){
    char*** ptr = malloc((numPtrArray+1) * sizeof(char**));
    for(int i=0; i<numPtrArray; i++){
        ptr[i] = malloc(MAXLEN * sizeof(char**));
    }
    ptr[numPtrArray] = NULL;
 
    char str[MAXLEN];
    scanf("%s", str);
 
    splitAndMap(ptr, str);
 
    for(int i=0; i<numPtrArray; i++){
        for(int j=0; ptr[i][j]!=NULL; j++)
            printf("%s ", ptr[i][j]);
        printf("\n");
    }
 
    for(int i=0; i<numPtrArray; i++) free(ptr[i]);
    free(ptr);
    return 0;
}
