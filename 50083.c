#include<stdio.h>

int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int x=0;
    while(scanf("%d",&x)!=EOF){
        if(c==0){
            if(x<=a){a-=x;}
            else if(x<=b){b-=x;}
        }
        else if(c==1){
            if(b>=a&&a-x>=0){a-=x;}
            else if(b>a&&a-x<0&&b-x>=0){b-=x;}
            else if(a>b&&b-x>=0){b-=x;}
            else if(a>b&&b-x<0&&a-x>=0){a-=x;}
        }
        printf("%d %d\n",a,b);
    }
    return 0;
}