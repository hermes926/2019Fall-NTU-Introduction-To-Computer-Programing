#include<stdio.h>
#include "max.h"

int max(int *iptr[], int n){ 
	int a=0; 
	for(int b=0;b<n;b++){
		int z=*(iptr[b]);
		if(z>a){
			a=z;
		}
	}
	return a;
}
