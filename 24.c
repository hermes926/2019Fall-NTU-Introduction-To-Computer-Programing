#include<stdio.h>
#include<ctype.h>

int main(){
    char a;
    int o1=0,o2=0,o3=0,o4=0;
    while(scanf("%c",&a)!=EOF){
        if(isdigit(a)){
            o1++;
        }
        if(isalpha(a)){
            o2++;
            if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U'){
                o3++;
            }
            else{
                o4++;
            }
        }
    
    }
    printf("%d %d %d %d\n",o1,o2,o3,o4);
}