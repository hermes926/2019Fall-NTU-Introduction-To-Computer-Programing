#include<stdio.h>
#include<ctype.h>

int main(){
    char a[105];
    int i=0;int con=0;int previ=0;
    while(scanf("%c",&a[i])!=EOF){
        
        if(isspace(a[i]) && con==0){
            continue;
        }
        else if(a[i]==10){
            int c=0;
            for(c=i-1;c>previ;c-=1){
                if(isspace(a[c])){
                    a[c]=0;}
                else{
                    break;
                }
            }
            for(int d=previ;d<=c;d++){
            printf("%c",a[d]);
            }
            previ=i;
            con=0;
        }
        else{
            con=1;i++;
        }
        


    }
    
    
    return 0;
}