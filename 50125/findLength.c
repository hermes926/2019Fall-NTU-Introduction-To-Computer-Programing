#include <stdio.h>
#include "findLength.h"


int findLength (int array[][256], int N, int r, int c, int dr, int dc){
	int maxlength=0,length=0;
	while(r>=0&&r<N&&c>=0&&c<N){
	if(array[r][c]==1){
		length++;
		if(maxlength<length){maxlength=length;		}
		
	}
	else{
		length=0;
	}
	r+=dr;c+=dc;
	
	
	}
	return maxlength;
	
	
}
