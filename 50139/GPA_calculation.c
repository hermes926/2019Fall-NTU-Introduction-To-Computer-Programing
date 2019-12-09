#include<stdio.h>
#include "GPA_calculation.h"

void GPA_calculation(struct Student all_student[], int N){
	double GPA[N];
	for(int i=0;i<N;i++){
		GPA[i] = 0.0;
		for(int j=0;j<all_student[i].N_class;j++){
			all_student[i].N_credit += all_student[i].all_class[j].academic_credit;
			switch(all_student[i].all_class[j].score[0]){
				case 'A':
					GPA[i] += (double)(4.0* all_student[i].all_class[j].academic_credit);
					break;
				case 'B':
					GPA[i] += (double)(3.0* all_student[i].all_class[j].academic_credit);
					break;
				case 'C':
					GPA[i] += (double)(2.0* all_student[i].all_class[j].academic_credit);
					break;
				default:
					break;		
			}
			switch(all_student[i].all_class[j].score[1]){
				case '+':
					GPA[i] += (double)(0.3* all_student[i].all_class[j].academic_credit);
					break;
				case '-':
					GPA[i] -= (double)(0.3* all_student[i].all_class[j].academic_credit);
					break;
				default:
					break;		
			}
		}
		GPA[i] /= (double)all_student[i].N_credit;
	}
	/*for(int i=0;i<N;i++)
		printf("%s %f\n", all_student[i].name ,GPA[i]) ;*/
	struct Student tempstu;double temp = 0.0;
	for(int i=1;i<N;i++){
		for(int j=0;j<i;j++){
			if(GPA[i] > GPA[j]){
				temp = GPA[i]; GPA[i] = GPA[j]; GPA[j] = temp;
				tempstu = all_student[i]; all_student[i] = all_student[j]; all_student[j] = tempstu;
			}
		}
	}
	/*for(int i=0;i<N;i++){
		printf("%d %s %f\n", i, all_student[i].name ,GPA[i] );
	}
	printf("------\n");*/
	for(int i=0;i<(int)((N+19)/20);i++){
		if(all_student[i].N_credit < 15 || GPA[i] < 3.38)
			continue;
		else{
			printf("%d %s %lf\n", i+1, all_student[i].name, GPA[i]);
		}
	}
	
}
