#include<stdio.h>
#include "evaluate_f.h"


int evaluate_f(int *iptr[], int n, int *index){
	int maxa=-1000000,a=0;
	for(int c=0;c<n;c++){
		a=*iptr[c]*4-(*(iptr[c]+1))*6;
		if(a>maxa){maxa=a;*index=c;		}
	}
	
	
	return maxa;
	
}
