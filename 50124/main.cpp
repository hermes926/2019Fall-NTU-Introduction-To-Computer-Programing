#include<stdio.h>
#include "validMoveNum.h"
#include "nextMove.h"

int main(){
	int n,m;
    scanf("%d%d",&n,&m);int pos[m][2];int steps[m];
    for(int c=0;c<m;c++){steps[c]=0;scanf("%d%d",&pos[c][0],&pos[c][1]);}
    int board[100][100];int con=0;
    for(int c=0;c<n;c++){
        for(int d=0;d<n;d++){
            board[c][d]=0;}
    }
    for(int c=0;c<m;c++){
            board[(pos[c][0])][(pos[c][1])]=10000*(c+1)+steps[c];
    }
    int eachcon=0;
    while(con==0){
        eachcon=0;
        for(int c=0;c<m;c++){    
        int maxway=0;
		maxway=nextMove(pos[c][0],pos[c][1],n,board);
        switch(maxway){
            case -1:
            	eachcon+=1;break;
			case 0:
            pos[c][0]-=2;pos[c][1]+=1;steps[c]++;break;
            case 1:
            pos[c][0]-=1;pos[c][1]+=2;steps[c]++;break;
            case 2:
            pos[c][0]+=1;pos[c][1]+=2;steps[c]++;break;
            case 3:
            pos[c][0]+=2;pos[c][1]+=1;steps[c]++;break;
            case 4:
            pos[c][0]+=2;pos[c][1]-=1;steps[c]++;break;
            case 5:
            pos[c][0]+=1;pos[c][1]-=2;steps[c]++;break;
            case 6:
            pos[c][0]-=1;pos[c][1]-=2;steps[c]++;break;
            case 7:
            pos[c][0]-=2;pos[c][1]-=1;steps[c]++;break;
	    default:
	    	
	    break;

        }
        board[(pos[c][0])][(pos[c][1])]=10000*(c+1)+steps[c];
        /*for(int e=0;e<n;e++){
                for(int f=0;f<n;f++){
                    printf("%3d ",board[e][f]);
                }   
                printf("\n");
                }
        printf("----\n");*/
	}
        if(eachcon==m){con=1;}    
    }
    for(int c=0;c<n;c++){
        for(int d=0;d<n;d++){
        if (d!=n-1){
        printf("%d ",board[c][d]);
        }
        else{
        printf("%d\n",board[c][d]);}
    }}
    return 0;
    
}
