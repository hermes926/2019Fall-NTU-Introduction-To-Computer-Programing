#include<stdio.h>
#include "transmission.h"

void transmission(long long int belt[],int N,int T){
	//printf("%d\n", belt[1] >> 63);
	int count = T / 64; 
	T %= 64;
	count %= N;
	long long int temp[count];
	for(int i=0;i<count;i++){
		temp[i] = belt[i];
	}
	for(int i=0;i<N-count;i++){
		belt[i]=belt[i+count];
	}
	for(int i=N-count;i<N;i++){
		belt[i]=temp[(i+count)%N];
	}
	
	for(int i=0;i<T;i++){
		long long int t = (belt[0] >> 63);
		if(t < 0)
			t = -t;
		//print(belt, N);
		for(int j=0;j<N;j++){
			belt[j] = belt[j] << 1;
			belt[j] += (j == N-1 ? t :
			((belt[j+1] >> 63) >= 0 ? (belt[j+1] >> 63) : -(belt[j+1] >> 63)));
		}
	}
}
