#include <stdio.h>
#define MAXP 10
#include "compute.h"
int main() {
    int N;
    paper P[MAXP] = {};
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s%d", P[i].journalName, &P[i].numCitedPaper);
        for (int j = 0; j < P[i].numCitedPaper; j++)
            scanf("%d", &P[i].citedPaperIndex[j]);
    }
    compute(P, N);
    return 0;
}
