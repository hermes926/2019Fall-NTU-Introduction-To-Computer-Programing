#include <stdio.h>
#include <stdlib.h>
#include "sumOfIntegers.h"
 
int main(int argc, char const *argv[])
{
    int a, b, c, d, number = 0;
    int *numberOfBlocks = &number;
    const int *ptrArray[16];
    int answer[16] = {0};
    scanf("%d%d%d%d", &a, &b, &c, &d);
    ptrArray[0] = &b;
    ptrArray[1] = &a;
    ptrArray[2] = &a;
    ptrArray[3] = NULL;
    ptrArray[4] = &d;
    ptrArray[5] = &a;
    ptrArray[6] = &b;
    ptrArray[7] = &b;
    ptrArray[8] = NULL;
    ptrArray[9] = &c;
    ptrArray[10] = NULL;
    ptrArray[11] = NULL;
    sumOfIntegers(ptrArray, answer, numberOfBlocks);
    for(int index = 0; index < *numberOfBlocks; index++) {
        printf("%d ", answer[index]);
    }
    return 0;
}
