#include<stdio.h>
#include "nextMove.h"
#include "validMoveNum.h"

int nextMove(int r, int c, int n, int visited[100][100]){
	int step[8]={9,9,9,9,9,9,9,9};
        if(r-1>=0&&r-1<n&&c-2>=0&&c-2<n&&visited[r-1][c-2]==0){
            step[6]=validMoveNum(r-1,c-2,n,visited);}
        if(r-1>=0&&r-1<n&&c+2>=0&&c+2<n&&visited[r-1][c+2]==0){
            step[1]=validMoveNum(r-1,c+2,n,visited);}
        if(r-2>=0&&r-2<n&&c-1>=0&&c-1<n&&visited[r-2][c-1]==0){
            step[7]=validMoveNum(r-2,c-1,n,visited);}
        if(r-2>=0&&r-2<n&&c+1>=0&&c+1<n&&visited[r-2][c+1]==0){
            step[0]=validMoveNum(r-2,c+1,n,visited);}
        if(r+1>=0&&r+1<n&&c-2>=0&&c-2<n&&visited[r+1][c-2]==0){
            step[5]=validMoveNum(r+1,c-2,n,visited);}
        if(r+1>=0&&r+1<n&&c+2>=0&&c+2<n&&visited[r+1][c+2]==0){
            step[2]=validMoveNum(r+1,c+2,n,visited);}
        if(r+2>=0&&r+2<n&&c-1>=0&&c-1<n&&visited[r+2][c-1]==0){
            step[4]=validMoveNum(r+2,c-1,n,visited);}
        if(r+2>=0&&r+2<n&&c+1>=0&&c+1<n&&visited[r+2][c+1]==0){
            step[3]=validMoveNum(r+2,c+1,n,visited);}
        int maxcount=9,maxway=-1;
        for(int d=0;d<8;d++){
            if(step[d]<maxcount){maxway=d;maxcount=step[d];}
        }
        return maxway;
	
}
