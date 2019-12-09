#include<stdio.h>
#include<string.h>

int main(){
    int useless=0;int outcount=0;
    char enter[130]={};
    char out[130]={};
    while(scanf("%s",enter)!=EOF){
        
        if(strlen(enter)==2 && ((enter[0]=='o'&& enter[1]=='f') ||(enter[0]=='a'&& enter[1]=='t'))){
            useless++;
        }
        else if(strlen(enter)==3 && ((enter[0]=='a'&& enter[1]=='n'&& enter[2]=='d') ||(enter[0]=='t'&& enter[1]=='h' && enter[2]=='e'))){
            useless++;
        }
        else if(strlen(enter)==4 && ((enter[0]=='a'&& enter[1]=='n'&& enter[2]=='d' && enter[3]=='.') ||(enter[0]=='t'&& enter[1]=='h' && enter[2]=='e' && enter[3]=='.'))){
            useless++;
        }
        else if(strlen(enter)==3 && ((enter[0]=='o'&& enter[1]=='f'&& enter[2]=='.') ||(enter[0]=='a'&& enter[1]=='t' && enter[2]=='.'))){
            useless++;
        }
        else{
            out[outcount]=enter[0]-32;
            outcount++;
        }
        if(enter[strlen(enter)-1]=='.'){
            for(int c=0;c<outcount;c++){
                printf("%c",out[c]);
            }
            printf("\n");
            char enter[130]={};
            outcount=0;
        }
    }
    return 0;
}