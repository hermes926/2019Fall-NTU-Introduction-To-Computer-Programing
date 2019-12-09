#include<stdio.h>
#include "constructPointerArray.h"
#define MAXN 1024
int R[MAXN][MAXN][2];
void constructPointerArray(const int A[MAXN][MAXN], const int *B[MAXN][MAXN], int N){
	
	//printf("1\n");
	int x=0,y=0;
	for(int c=0;c<N;c++){
		for(int d=0;d<N;d++){
			x=A[c][d]/N;
			y=A[c][d]%N;
			//printf("%d %d",x,y);
			R[x][y][0] = c;
			R[x][y][1] = d;
			//printf(" %d %d\n", R[x][y][0], R[x][y][1]);
		}
	}
	/*for(int c=0;c<N;c++){
		for(int d=0;d<N;d++){
			printf("%d ", A[R[c][d][0]][R[c][d][1]]);
		}
		printf("\n");
	}*/
	for(int c=0;c<N;c++){
		for(int d=0;d<N;d++){
			if(d+1<N){
			B[R[c][d][0]][R[c][d][1]]=&A[R[c][d+1][0]][R[c][d+1][1]];}
			else if(c+1<N){
				B[R[c][d][0]][R[c][d][1]]=&A[R[c+1][0][0]][R[c+1][0][1]];
			}
			else{
				B[R[c][d][0]][R[c][d][1]]=&A[R[0][0][0]][R[0][0][1]];
			}
		}
	}
	
	
	
}
