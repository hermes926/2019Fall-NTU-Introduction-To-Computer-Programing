#include<stdio.h>

int gcd(int,int);
int main(){
    int y,x,count=0;
    while(scanf("%d",&x)!=EOF){
        if(count==0){y=x;}
        
        else{y=(x*y)/gcd(x,y);/*printf("%d\n",gcd(x,y));*/}
        count++;
    }
    printf("%d\n",y);
    return 0;

}

int gcd(int a,int b){
    int f=0;
    if(b>a){f=b;b=a;a=f;}

    if (b != 0)
       return gcd(b, a%b);
    else 
       return a;

}