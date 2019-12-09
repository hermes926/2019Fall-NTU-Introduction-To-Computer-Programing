#include<stdio.h>
#include "snake.h"

void snake(const int *ptr_array[100][100], int m){
	int *tptr=ptr_array[0][0];
	for(int a<=0;a<m;a++){
		for(int b=0;b<m;b++){
			for(int c=0;c<=a;c++){
				if(c!=a){
					for(int d=0;d<m;d++){
						if(*ptr_array[c][d]<*ptr_array[a][b]){
							tptr=ptr_array[c][d];ptr_array[c][d]=ptr_array[a][b];ptr_array[a][b]=tptr;
						}
					}
				}
				else{
					for(int d=0;d<b;d++){
						if(*ptr_array[c][d]<*ptr_array[a][b]){
							tptr=ptr_array[c][d];ptr_array[c][d]=ptr_array[a][b];ptr_array[a][b]=tptr;
						}}}}}}
	
}
