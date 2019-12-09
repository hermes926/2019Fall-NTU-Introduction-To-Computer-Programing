#include<stdio.h>

int stepcount(int l,int x,int y,int z[l][l]){
    int step=0;
    if(x-1>=0 && x-1<l && y-2>=0 && y-2<l && z[x-1][y-2] == 0){step++;}
    if(x-1>=0&&x-1<l&&y+2>=0&&y+2<l&&z[x-1][y+2]==0){step++;}
    if(x-2>=0&&x-2<l&&y-1>=0&&y-1<l&&z[x-2][y-1]==0){step++;}
    if(x-2>=0&&x-2<l&&y+1>=0&&y+1<l&&z[x-2][y+1]==0){step++;}
    if(x+1>=0&&x+1<l&&y-2>=0&&y-2<l&&z[x+1][y-2]==0){step++;}
    if(x+1>=0&&x+1<l&&y+2>=0&&y+2<l&&z[x+1][y+2]==0){step++;}
    if(x+2>=0&&x+2<l&&y-1>=0&&y-1<l&&z[x+2][y-1]==0){step++;}
    if(x+2>=0&&x+2<l&&y+1>=0&&y+1<l&&z[x+2][y+1]==0){step++;}
    return step;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);int pos[m][2];int steps[m];
    for(int c=0;c<m;c++){steps[c]=0;scanf("%d%d",&pos[c][0],&pos[c][1]);}
    int board[n][n];int con=0;
    for(int c=0;c<n;c++){
        for(int d=0;d<n;d++){
            board[c][d]=0;}
            }
    int eachcon=0;
    for(int c=0;c<m;c++){
            board[(pos[c][0])][(pos[c][1])]=10000*(c+1)+steps[c];
        }
    while(con==0){
        eachcon=0;
        for(int c=0;c<m;c++){    
        int step[8]={9,9,9,9,9,9,9,9};
        if((pos[c][0])-1>=0&&(pos[c][0])-1<n&&(pos[c][1])-2>=0&&(pos[c][1])-2<n&&board[(pos[c][0])-1][(pos[c][1])-2]==0){
            step[6]=stepcount(n,(pos[c][0])-1,(pos[c][1])-2,board);}
        if((pos[c][0])-1>=0&&(pos[c][0])-1<n&&(pos[c][1])+2>=0&&(pos[c][1])+2<n&&board[(pos[c][0])-1][(pos[c][1])+2]==0){
            step[1]=stepcount(n,(pos[c][0])-1,(pos[c][1])+2,board);}
        if((pos[c][0])-2>=0&&(pos[c][0])-2<n&&(pos[c][1])-1>=0&&(pos[c][1])-1<n&&board[(pos[c][0])-2][(pos[c][1])-1]==0){
            step[7]=stepcount(n,(pos[c][0])-2,(pos[c][1])-1,board);}
        if((pos[c][0])-2>=0&&(pos[c][0])-2<n&&(pos[c][1])+1>=0&&(pos[c][1])+1<n&&board[(pos[c][0])-2][(pos[c][1])+1]==0){
            step[0]=stepcount(n,(pos[c][0])-2,(pos[c][1])+1,board);}
        if((pos[c][0])+1>=0&&(pos[c][0])+1<n&&(pos[c][1])-2>=0&&(pos[c][1])-2<n&&board[(pos[c][0])+1][(pos[c][1])-2]==0){
            step[5]=stepcount(n,(pos[c][0])+1,(pos[c][1])-2,board);}
        if((pos[c][0])+1>=0&&(pos[c][0])+1<n&&(pos[c][1])+2>=0&&(pos[c][1])+2<n&&board[(pos[c][0])+1][(pos[c][1])+2]==0){
            step[2]=stepcount(n,(pos[c][0])+1,(pos[c][1])+2,board);}
        if((pos[c][0])+2>=0&&(pos[c][0])+2<n&&(pos[c][1])-1>=0&&(pos[c][1])-1<n&&board[(pos[c][0])+2][(pos[c][1])-1]==0){
            step[4]=stepcount(n,(pos[c][0])+2,(pos[c][1])-1,board);}
        if((pos[c][0])+2>=0&&(pos[c][0])+2<n&&(pos[c][1])+1>=0&&(pos[c][1])+1<n&&board[(pos[c][0])+2][(pos[c][1])+1]==0){
            step[3]=stepcount(n,(pos[c][0])+2,(pos[c][1])+1,board);}
        //printf("%d %d %d %d %d %d %d %d\n",step[0],step[1],step[2],step[3],step[4],step[5],step[6],step[7]);
        int maxcount=9,maxway=-1;
        for(int d=0;d<8;d++){
            if(step[d]<maxcount){maxway=d;maxcount=step[d];}
            if(step[d]!=9){eachcon=1;}
        }
        switch(maxway){
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
        if(eachcon==0){con=1;}
    
        
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
    
    