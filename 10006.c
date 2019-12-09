#include<stdio.h>

int main(){
    int a,sum=0;
    while(scanf("%d",&a)!=EOF){
        sum=sum+a;
    }
    printf("%d\n",sum);
    return 0;
}
