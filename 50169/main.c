#include <stdio.h>
#include <stdlib.h>
#include "sumOfIntegers.h"
 
int main(int argc, char const *argv[])
{
    int a, b, c, d, e, f, g, h, number = 0;
    int *numberOfBlocks = &number;
    const int *ptrArray[32];
    int answer[32] = {0};
    scanf("%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h);
    ptrArray[0] = &b;
    ptrArray[1] = NULL;
    ptrArray[2] = &c;
    ptrArray[3] = &e;
    ptrArray[4] = &a;
    ptrArray[5] = &b;
    ptrArray[6] = &a;
    ptrArray[7] = &c;
    ptrArray[8] = &c;
    ptrArray[9] = &g;
    ptrArray[10] = &c;
    ptrArray[11] = &b;
    ptrArray[12] = &g;
    ptrArray[13] = &e;
    ptrArray[14] = &a;
    ptrArray[15] = &f;
    ptrArray[16] = &g;
    ptrArray[17] = &b;
    ptrArray[18] = &a;
    ptrArray[19] = &a;
    ptrArray[20] = NULL;
    ptrArray[21] = &d;
    ptrArray[22] = NULL;
    ptrArray[23] = &c;
    ptrArray[24] = &g;
    ptrArray[25] = &e;
    ptrArray[26] = &d;
    ptrArray[27] = NULL;
    ptrArray[28] = &c;
    ptrArray[29] = NULL;
    ptrArray[30] = NULL;
    sumOfIntegers(ptrArray, answer, numberOfBlocks);
    for(int index = 0; index < *numberOfBlocks; index++) {
        printf("%d ", answer[index]);
    }
    return 0;
}
