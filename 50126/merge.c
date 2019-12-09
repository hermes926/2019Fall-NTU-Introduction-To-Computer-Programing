#include<stdio.h>
#include<stddef.h>
#include<stdbool.h>


void merge(int A[], int B[], int* a[], int* b[]){
	int c=0;int d=0;int maxc=0,maxd=0;
	while(a[maxc]!=NULL){
		maxc++;
	}
	while(b[maxd]!=NULL){
		maxd++;
	}
	bool con;
	if(A[0]>B[0]){d++;con=true;}
	else{c++;con=false;}
	while(c<=maxc && d<=maxd){
			
			if(A[c]>B[d]){
				if(con){
					b[d-1]=&B[d];
				}
				else{
					a[c-1]=&B[d];
				}
				d++;con=true;
			
			}
			else{
				if(con){
					b[d-1]=&A[c];
				}
				else{
					a[c-1]=&A[c];
				}
				c++;con=false;
			}}
	if(con){b[d-1]=&A[c];	}
	else{a[c-1]=&B[d];	}
}
