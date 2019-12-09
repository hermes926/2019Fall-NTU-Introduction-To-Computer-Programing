#include<stdio.h>

int main(){
    char a;int con=0;int star=0;
    while(scanf("%c",&a)!=EOF){
        if(con==1){
            if(a==10){star++;con=0;}
            else if(a==32){con=2;}
            else{con=0;}
        }
        else if(con==2){
            if(a==32){star++;}
            con=0;
   
        }
        if(a=='.'){
            con=1;
        }

    }
    if(con!=0){
        star++;
    } 
    printf("%d\n",star);
    
    return 0;
}