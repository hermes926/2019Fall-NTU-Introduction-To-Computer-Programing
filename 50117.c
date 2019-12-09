#include<stdio.h>

int main(){
    int a=0,b=0,f=0,e=0,count=0;
    scanf("%d",&a);
    while(scanf("%d",&b)!=EOF){
        
        if(count==0&&b<a){e=b;}
        else if(count==0&&b>=a){e=b%a;f=(b-(b%a))/a;printf("%d\n",f);}
        else{
            f=((b+e*10)-(b+e*10)%a)/a;
            printf("%d\n",&f);
            e=(b+e*10)%a;
        }
        count++;
    }
    return 0;
}