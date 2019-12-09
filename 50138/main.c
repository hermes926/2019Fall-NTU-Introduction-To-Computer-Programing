#include <stdio.h>
#include "computeGrade.h"
 
int main()
{
    Classes classes[2];
    scanf("%d", &classes[0].numStudent);
    for (int i = 0; i < classes[0].numStudent; i++) {
        scanf("%s", classes[0].student[i].id);
        for (int j = 0; j < 18; j++) {
            scanf("%d", &classes[0].student[i].score[j].rawScore);
        }
    }
    scanf("%d", &classes[1].numStudent);
    for (int i = 0; i < classes[1].numStudent; i++) {
        scanf("%s", classes[1].student[i].id);
        for (int j = 0; j < 18; j++) {
            scanf("%d", &classes[1].student[i].score[j].rawScore);
        }
    }
    computeGrade(classes);
    return 0;
}
