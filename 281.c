#include<stdio.h>

int main(){
    char test[24];
    /*for(int c=0;c<24;c++){
        test[c]=1;
    }*/
    int a=0;
    while(scanf("%d",&a)!=EOF){
        int output=0;
        char enter[32];
        for(int c=0;c<32;c++){
            enter[c]=a%2;
            a=a/2;
            output+=enter[c];
        }
        
        printf("%d\n",output);
    }

    return 0;
}