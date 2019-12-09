#include<stdio.h>

int main(){
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    double f=c*c*0.75;
    if(c>a){f=f+(c-a)*(c-a)*0.25;}
    if(c>b){f=f+(c-b)*(c-b)*0.25;}
    printf("%lf\n",f*3.1415926);
    return 0;
}