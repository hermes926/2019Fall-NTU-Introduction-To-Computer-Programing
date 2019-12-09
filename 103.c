#include<stdio.h>

int main(){
    int a;
    scanf("%d",&a);
    double m[a][a];
    for(int b=0;b<a;b++){
        for(int c=0;c<a;c++){
            scanf("%lf",&m[b][c]);}}
    double y[a],x[a];
    for(int b=0;b<a;b++){scanf("%lf",&y[b]);}
    for(int b=a-1;b>=0;b=b-1){double z=y[b];
        for(int c=a-1;c>b;c=c-1){
            z=z-m[b][c]*x[c];
        }
        x[b]=z/m[b][b];
    }
    for(int b=0;b<a;b++){
        printf("%f\n",x[b]);
    }


    return 0;        
}