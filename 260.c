#include<stdio.h>
#include<string.h>

int main(){
    char enter[128]={},final[128]={};int count=0;
    while(scanf("%s",enter)!=EOF){
        //printf("%d\n",strlen(enter));
        if(count==0){
            for(int c=0;c<strlen(enter);c++){
                final[c]=enter[c];
            }
            count++;
        }
        else{
            int simnum=0,simcon=0;
            //printf("%d %d\n",strlen(final),strlen(enter));
            for(int c=0;(c<strlen(final) && c<strlen(enter));c++){
                simcon=1;
                for(int d=0;d<=c;d++){
                    if(enter[d]!=final[strlen(final)-c+d-1]){
                        simcon=0;
                    }
                }
                if(c+1>simnum && simcon==1){
                    simnum=c+1;
                }
            }
            int lengthe=strlen(enter);
            int lengthf=strlen(final);
            for(int c=0;c<lengthe-simnum;c++){
                final[c+lengthf]=enter[c+simnum];
            }
        }
        //printf("%d\n",strlen(final));
    
        
    }
    for(int c=0;c<strlen(final);c++){
        printf("%c",final[c]);
    }
    
    
    return 0;
}