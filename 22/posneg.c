#include<stdio.h>
#include "posneg.h" 

void posneg(int array[5][5], int result[2]){
	for(int a=0;a<5;a++){
		for(int b=0;b<5;b++){
			if(array[a][b]>0){
				result[1]++;
			}
			else if(array[a][b]<0){
				result[0]++;
			}
		}
	}
}
