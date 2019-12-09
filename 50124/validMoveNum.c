#include<stdio.h>
#include "validMoveNum.h"

int validMoveNum(int r, int c, int n, int visited[100][100]){
	int step=0;
    if(r>=n || r<0 || c>=n || c<0){
    	step=-1;
	}
	else{
		if(r-1>=0 && r-1<n && c-2>=0 && c-2<n && visited[r-1][c-2] == 0){step++;}
	    if(r-1>=0&&r-1<n&&c+2>=0&&c+2<n&&visited[r-1][c+2]==0){step++;}
	    if(r-2>=0&&r-2<n&&c-1>=0&&c-1<n&&visited[r-2][c-1]==0){step++;}
	    if(r-2>=0&&r-2<n&&c+1>=0&&c+1<n&&visited[r-2][c+1]==0){step++;}
	    if(r+1>=0&&r+1<n&&c-2>=0&&c-2<n&&visited[r+1][c-2]==0){step++;}
	    if(r+1>=0&&r+1<n&&c+2>=0&&c+2<n&&visited[r+1][c+2]==0){step++;}
	    if(r+2>=0&&r+2<n&&c-1>=0&&c-1<n&&visited[r+2][c-1]==0){step++;}
	    if(r+2>=0&&r+2<n&&c+1>=0&&c+1<n&&visited[r+2][c+1]==0){step++;}}
    return step;
} 
