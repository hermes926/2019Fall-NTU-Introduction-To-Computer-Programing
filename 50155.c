#include<stdio.h>

int main(){
    int a,b,c,d,e,f,g;int depth=0;
    scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
    if(d==0){depth=0;}
    else{
    if((a*b*d+e*f*g)/(a*b)<g){depth=(a*b*d)/(a*b-e*f);}
    else {
        if(e*f*g<(b*a*(c-d))){depth=(((a*b*d)+(e*f*g))/(a*b));}
        else{
            if(e*f*g>=a*b*c){depth=0;}
            else{depth=c;}
        }
    }}
    printf("%d\n",depth);
    return 0;
}