#include<stdio.h>

int main(){
    int a,b;char s1,s0;
    scanf("%d%d\n%c %c",&a,&b,&s1,&s0);
    unsigned int x=0;int count=0;
    while(scanf("%u",&x)!=EOF){
        int array[32];
        for(int c=31;c>=0;c-=1){
            array[c]=x%2;
            x=x/2;   
        }
        for(int c=0;c<32;c++){
            (array[c]==1)?(printf("%c",s1)):printf("%c",s0);
            count++;
            if(count%a == 0){
                printf("\n");
                if(count==a*b){
                    break;
                }
                
            }
        }
        
    }
    
    return 0;
}