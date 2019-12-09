#include<stdio.h>
#include "prepare_array.h"

void prepare_array(int buffer[], int *array[], int row, int column[]){
	int z=0;
	for(int c=0;c<row;c++){
		array[c]=&buffer[z];
		z+=column[c];
	} 
}
