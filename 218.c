#include<stdio.h>

int met(int a,int b){
    int c=1;
    for(int d=0;d<b;d++){
        c=c*(a-d);}
    for(int d=0;d<b;d++){
        c=c/(d+1);}
    return c;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int count=0;
    for(int c=0;c<=m;c++){
        count=count+met(n,c);
    }
    printf("%d\n",count);
    return 0;
}