#include<stdio.h>

int main(){
    int a,b,c,f=0;
    
    while(scanf("%d",&a)!=EOF){
       
        for(int d=a;d>0;d=(d-(d%10))/10){
           if(d<10){if(d!=c){b=0;}} 
        }
        for(int d=a;d>0;d=(d-(d%10))/10){
           b++; 
        }
        c=a%10;
        if(b>f){f=b;}
    }
    printf("%d\n",f);
    return 0;
}