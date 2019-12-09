#include<stdio.h>
#include<stdbool.h>
#include "sumOfIntegers.h"

void sumOfIntegers(const int *ptrArray[], int answer[], int *numberOfBlocks){
	int sum=0,nowcount=0;bool con=true;
	for(int c=0;;c++){
		if(c!=0 && ptrArray[c]==NULL && ptrArray[c-1]==NULL){break;		}
		else if(ptrArray[c] == NULL){
			nowcount= c+1;
			answer[*(numberOfBlocks)]=sum;
			*numberOfBlocks += 1;
			sum=0;
		}
		
		else{
			con = true;
			for(int d=nowcount;d<c;d++){
				if(ptrArray[c] == ptrArray[d]){
					con = false;
				};
			}
			if(con){sum+= *(ptrArray[c]);		}
		}
	}
	
}
