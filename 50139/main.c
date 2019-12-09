#include <stdio.h>
#include "GPA_calculation.h"
 
int main(int argc, char const *argv[])
{
    struct Student all_student[10000];
    int N, i, j;
 
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%s%d", all_student[i].name, &all_student[i].N_class);
        for(j = 0; j < all_student[i].N_class; j++){
            scanf("%d%s", &all_student[i].all_class[j].academic_credit, all_student[i].all_class[j].score);
        }
        all_student[i].N_credit = 0;
        all_student[i].GPA = 0.0;
    }
 
    GPA_calculation(all_student, N);
 
    return 0;
}
