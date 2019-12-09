#include<stdio.h>
#include <stddef.h>
#include "card.h"

void shuffle(int *deck[]){
	int c=0;
	int *odd[5000],*even[5000];int oddc=0;int evenc=0;
	while(deck[c]!=NULL){
		c++;
	}
	int count=0;
	while(count<((c+1)/2)){
		odd[count]=deck[count];
		count++;
	}
	int count2=0;
	while(count<c){
		even[count2]=deck[count];
		count++;count2++;		
	}
	c=0;oddc=0;evenc=0;
	while(deck[c]!=NULL){
		if(c%2==0){
			deck[c]=odd[oddc];
			oddc++;
		}
		else{
			deck[c]=even[evenc];
			evenc++;
		}
		c++;
		//printf("%d\n",*deck[c]);
	}
	
}

void print(int *deck[]){
	int c=0;int z=0;
	while(deck[z]!=NULL){
		z++;
	}
	
	while(deck[c]!=NULL){
		if(c!=z-1){printf("%d ",*deck[c]);
	}
		else{
			printf("%d\n",*deck[c]);
		}
		c++;
	}
}
