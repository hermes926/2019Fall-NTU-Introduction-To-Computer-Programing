#include<stdio.h>
#include<string.h>

int main(){
    int time=0;int similarity=0;
    scanf("%d",&time);
    for(int c=0;c<time;c++){
        similarity=1;int diff=0,diffnum1=-1,diffnum2=-1;int time=0;
        char s1[85],s2[85];
        scanf("%s%s",s1,s2);
        if(strlen(s1)==strlen(s2)){
            for(int d=0;d<strlen(s1);d++){
                if(s1[d]!=s2[d] ){
                    diff++;
                    if(diffnum1==-1){diffnum1=d;}
                    else{diffnum2=d;}
                }
            }
            //printf("%d %d %d ",diff,diffnum1,diffnum2);
            if(diff==1 || diff>=3){similarity=0;}
            else if(diff==2 && (s1[diffnum1]!=s2[diffnum2] || s1[diffnum2]!=s2[diffnum1])){similarity=0;}
        }
        else if(strlen(s1)-strlen(s2)==1){
            for(int d=0;d<strlen(s2);d++){
                if(time==0 && s1[d]!=s2[d]){
                    for(int e=d;e<strlen(s2);e++){
                        s1[e]=s1[e+1];
                        //printf("%c",s1[d]);
                    }
                    time=1;d-=1;
                }
                else if(time==1 && s1[d]!=s2[d]){
                    similarity=0;
                }
            }
        }
        else if(strlen(s2)-strlen(s1)==1){
            for(int d=0;d<strlen(s1);d++){
                if(time==0 && s1[d]!=s2[d]){
                    for(int e=d;e<strlen(s1);e++){
                        s2[e]=s2[e+1];
                    }
                    time=1;d-=1;
                }
                else if(time==1 && s1[d]!=s2[d]){
                    similarity=0;
                }
            }
        }
        else{
            similarity=0;
        }
        similarity==1?printf("yes\n"):printf("no\n");
    }
    
    
    return 0;
}