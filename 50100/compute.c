#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "compute.h"

void compute(paper P[], int N){
	char name[N][64];int namecount[N];int citedcount[N];
	int k=0;
	for(int i=0;i<N;i++){
		bool find = false;
		for(int j=0;j<k;j++){
			if(strcmp(name[j], P[i].journalName) == 0){
				namecount[j]++;find = true;break;
			}
		}
		if(!find){
			strcpy(name[k], P[i].journalName);
			namecount[k] = 1;citedcount[k] = 0;
			k++;
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<P[i].numCitedPaper;j++){
			for(int c=0;c<k;c++){
				if(strcmp(P[P[i].citedPaperIndex[j]].journalName, name[c]) == 0){
					citedcount[c]++;break;
				}
			}
		}
	}
	char temp[64];int tempnamecount = 0, tempcitedcount = 0;
	for(int i=1;i<k;i++){
		for(int j=0;j<i;j++){
			if(strcmp(name[i], name[j]) < 0){
				strcpy(temp, name[i]);strcpy(name[i], name[j]);strcpy(name[j], temp);
				tempnamecount = namecount[i];namecount[i] = namecount[j];namecount[j] = tempnamecount;
				tempcitedcount = citedcount[i];citedcount[i] = citedcount[j];citedcount[j] = tempcitedcount;
			}
		}
	}
	
	for(int i=0;i<k;i++){
		printf("%s %d/%d\n", name[i], citedcount[i], namecount[i]);
	}
	
}

