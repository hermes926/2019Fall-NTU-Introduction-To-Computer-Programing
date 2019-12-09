#include<stdio.h>

int main(){
    char a;int al[26];
    for(int c=0;c<26;c++){
        al[c]=0;}
    
    while(scanf("%c",&a)!=EOF){
        for(int c=0;c<26;c++){
            if(a==65+c||a==97+c){
                al[c]++;
            }
        }
    }
    for(int c=0;c<26;c++)
        {printf("%d\n",al[c]);}
    return 0;
}