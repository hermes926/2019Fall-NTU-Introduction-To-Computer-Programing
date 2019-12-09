#include<stdio.h>

int main(){
    char test[24];
    /*for(int c=0;c<24;c++){
        test[c]=1;
    }*/
    int a=0;
    while(scanf("%d",&a)!=EOF){
        int output=0;int maxoutput=0;
        char enter[32];
        for(int c=0;c<32;c++){
            enter[c]=a%2;
            a=a/2;
            if(enter[c]==1){
                output++;
                if(output>maxoutput){
                    maxoutput=output;
                }
            }
            else{
                output=0;
            }
        }
        
        printf("%d\n",maxoutput);
    }

    return 0;
}