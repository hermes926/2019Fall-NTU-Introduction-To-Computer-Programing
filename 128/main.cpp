#include<stdio.h>
#include "intersection.h"

int main(){
	int z[100][100];int y[4]={0,0,0,0};
	for(int a=0;a<100;a++){
		for(int b=0;b<100;b++){
			scanf("%d",&z[a][b]);
		}
	}
	intersection(z,y);
	for(int a=0;a<4;a++){
	printf("%d\n",y[a]);
	}
	return 0;
	
}
