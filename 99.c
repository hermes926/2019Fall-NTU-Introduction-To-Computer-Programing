#include<stdio.h>

int main(){
    int m,n;
    scanf("%d%d",&n,&m);
    int board[n][m][m];
    char name[n][64];
    int winner[n];
    int rowsum[n][m];
    int colsum[n][m];
    int diasum[n][2];
    for(int c=0;c<n;c++){
        winner[c]=0;diasum[c][0]=0;diasum[c][1]=0;
        scanf("%s",name[c]);
        for(int d=0;d<m;d++){
            rowsum[c][d]=0;colsum[c][d]=0;
        }
        for(int d=0;d<m;d++){
            for(int e=0;e<m;e++){
                scanf("%d",&board[c][d][e]);
                rowsum[c][d]+=board[c][d][e];
                colsum[c][e]+=board[c][d][e];
                if(d==e){diasum[c][0]+=board[c][d][e];}
                if(d+e == m-1){diasum[c][1]+=board[c][d][e];}
            }
        }
        
    }
    int num=0;
    int anw=0;int e=0,f=0,d=0;int e1=-1,f1=-1;
    for(int c=0;c<m*m;c++){
        scanf("%d",&num);
        for(d=0;d<n;d++){
            e1=-1;f1=-1;
            for(f=0;f<m;f++){
                if(e1!=-1){break;}
                for(e=0;e<m;e++){
                    if(num == board[d][f][e]){
                        board[d][f][e]=0;e1=e;f1=f;break;
        }}}
                rowsum[d][f1]-=num;
                colsum[d][e1]-=num;
                if(f1==e1){diasum[d][0]-=num;}
                if(f1+e1 == m-1){diasum[d][1]-=num;}
                //printf("%d %d %d %d\n",rowsum[d][f1],colsum[d][e1],diasum[d][0],diasum[d][1]);
                if(rowsum[d][f1]==0 || colsum[d][e1]==0 || diasum[d][0]==0 || diasum[d][1]==0){
                    winner[d]=1;anw=num;
        }}
        if(anw!=0){
            printf("%d",anw);
        for(int d=0;d<n;d++){
            if(winner[d]==1){
                 printf(" %s",name[d]);
            }
        }
        break;}
    }
    return 0;
}