#include<stdio.h>
#include "intersection.h"

void intersection(int map[100][100], int result[4]){
		int c[102][102];
		for(int d=0;d<102;d++){
			for(int e=0;e<102;e++){
				if(d>0&&d<101&&e>0&&e<101){
					c[d][e]=map[d+1][e+1];
				}
				else{c[d][e]=0;}}}
		
		
		for(int d=1;d<=100;d++){
		for(int e=1;e<=100;e++){
			if(c[d][e]==1){
			if(c[d+1][e]==1&&c[d-1][e]==1&&c[d][e-1]==1&&c[d][e+1]==1){
				result[0]++;	}
			else if(c[d+1][e]+c[d-1][e]+c[d][e-1]+c[d][e+1]==3){
				result[1]++;
			}
			else if(c[d+1][e]+c[d-1][e]+c[d][e-1]+c[d][e+1]==2&&c[d+1][e]+c[d-1][e]!=2&&c[d][e+1]+c[d][e-1]!=2){
				result[2]++;
			}
			else if(c[d+1][e]+c[d-1][e]+c[d][e-1]+c[d][e+1]==1){
				result[3]++;
			}
			}	}}
	
	return;
}
