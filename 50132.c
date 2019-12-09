#include<stdio.h>

int main(){
    char a;char preva=123;int final=0;
    while(scanf("%c",&a)!=EOF){
        if(a<98 || a>122 || a==101 || a==105 || a==111 || a==117){
            continue;
        }
        else{
            if(preva<a){
                final++;
                
            }
            preva=a;
        }

    }
    printf("%d\n",final);
    
    return 0;
}