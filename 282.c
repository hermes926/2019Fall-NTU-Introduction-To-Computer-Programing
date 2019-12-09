#include<stdio.h>

int main(){
    char test[24];
    /*for(int c=0;c<24;c++){
        test[c]=1;
    }*/
    long long int a=0;
    while(scanf("%lld",&a)!=EOF){
        int output=0;int maxoutput=0;
        char enter[64];
        for(int c=0;c<64;c++){
            enter[c]=a%2;
            a=a/2;
            maxoutput+=enter[c];
        }
        
        printf("%d\n",maxoutput);
    }

    return 0;
}