#include<stdio.h>
#include "computeGrade.h"

void computeGrade(Classes classes[2]){
	double classavg[2][18];double student_final_scaled_score[2][1000];
	for(int j=0;j<18;j++){
		for(int i=0;i<2;i++){
			classavg[i][j] = 0.0;
			for(int k=0;k<classes[i].numStudent;k++){
				classavg[i][j] += classes[i].student[k].score[j].rawScore;
			}
			classavg[i][j] = (double) classavg[i][j] / classes[i].numStudent;
		}
		double modifier = ((classavg[0][j] > classavg[1][j]) ? (classavg[0][j] / classavg[1][j]) : (classavg[1][j] / classavg[0][j]));
		if(classavg[0][j] > classavg[1][j]){
			for(int k=0;k<classes[1].numStudent;k++)
				classes[1].student[k].score[j].scaledScore = (double)modifier * classes[1].student[k].score[j].rawScore;
			for(int k=0;k<classes[0].numStudent;k++)
				classes[0].student[k].score[j].scaledScore = (double)classes[0].student[k].score[j].rawScore;
				
		}
		else{
			for(int k=0;k<classes[0].numStudent;k++)
				classes[0].student[k].score[j].scaledScore = (double)modifier * classes[0].student[k].score[j].rawScore;
			for(int k=0;k<classes[1].numStudent;k++)
				classes[1].student[k].score[j].scaledScore = (double)classes[1].student[k].score[j].rawScore;	
		}  
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<classes[i].numStudent;j++){
			student_final_scaled_score[i][j] = 0.0;
			for(int k=0;k<18;k++){
				if(classes[i].student[j].score[k].scaledScore > 100.0)
					classes[i].student[j].score[k].scaledScore = 100.0;
				student_final_scaled_score[i][j] += classes[i].student[j].score[k].scaledScore;
			}
			student_final_scaled_score[i][j] *= 0.06;
			if(student_final_scaled_score[i][j] > 100.0)
				student_final_scaled_score[i][j] = 100.0; 
			printf("%s %f\n",  classes[i].student[j].id, student_final_scaled_score[i][j]);
		}
	}
	
	
	
}
