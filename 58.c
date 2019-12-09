#include<stdio.h>

void findlake(int n, int m, int map[n][m],int *area,int x,int y){
    (*area)++;
    map[x][y]=0;
    if(x+1<n && map[x+1][y]==1){findlake(n,m,map,area,x+1,y);}
    if(x-1>=0 && map[x-1][y]==1){findlake(n,m,map,area,x-1,y);}
    if(y+1<m && map[x][y+1]==1){findlake(n,m,map,area,x,y+1);}
    if(y-1>=0 && map[x][y-1]==1){findlake(n,m,map,area,x,y-1);}
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int map[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&map[i][j]);
        }
    }
    int area=0;int *areaptr=&area;
    int final[((n*m)/2)+1];int fcon=0;
    for(int i=0;i<((n*m)/2)+1;i++){
        final[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==1){
                findlake(n,m,map,areaptr,i,j);
                final[fcon]=*areaptr;
                fcon++;
                //printf("%d\n",*areaptr);
                *areaptr=0;
            }
        }
    }
    int t=0;
    for(int i=0;i<fcon;i++){
        for(int j=0;j<i;j++){
            if(final[i]>final[j]){
                t=final[j];final[j]=final[i];final[i]=t;
            }
        }
    }
    t=0;
    while(final[t]!=0 && t<((n*m)/2)+1){
        printf("%d\n",final[t]);
        t++;
    }

    return 0;
}