#include<stdio.h>
#include<stdbool.h>
 
bool ok(int color[],int n,bool arr[n][n]){
    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] ? printf("1 ") : printf("0 ");
        }
        printf("\n");
    }*/
    bool fin=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(color[i]==color[j] && (!arr[i][j])){
                fin=false;//printf("%d %d\n",i,j);
                break;
            }
        }
        if(!fin){break;}
    }
    return fin;
}
 
int main(){
    int n,c,p;
    scanf("%d%d%d",&n,&c,&p);
    bool pair[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pair[i][j]=true;
        }
    }
 
    int x,y;
    for(int i=0;i<p;i++){
        scanf("%d%d", &x,&y);
        pair[x][y]=false;pair[y][x]=false;
    }
 
 
    //printf("------\n");
    int color[n];long long int time=1;
    for(int i=0;i<n;i++){
        color[i]=0;time *= c;
    }
    long long int z=0;
 
    while(z<time){
        long long int y=z;
        for(int i=0;i<n;i++){
            color[i]=y%c;y/=c;
            //printf("%d ",color[i]);
        }
       // printf("\n");
        if(ok(color,n,pair)){
            for(int i=0;i<n;i++){
                printf("%d\n",color[i]+1);
            }
            break;
        }
 
 
        z++;
    }
    if(z==time){
        printf("no solution.\n");
    }
 
    return 0;
}