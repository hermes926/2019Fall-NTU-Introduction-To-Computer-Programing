#include<stdio.h>
#include "max.h"

int max(int array[5][5]) {
    int a=-100000;
    for(int b=0;b<5;b++){
    	for(int c=0;c<5;c++){
    		if(array[b][c]>a){
    			a=array[b][c];}
		}
	}
	return a;
	
}
