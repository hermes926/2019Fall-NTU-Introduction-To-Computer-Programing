#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int calculater(char in[]){
    int f=0;int multi=1;
    for(int c=0;c<strlen(in)-1;c++){
        multi*=10;
    }
    for(int c=0;c<strlen(in);c++){
        f+=(in[c]-48)*multi;multi/=10;
    }
    //printf("%d",f);
    return f;
}


int main(){
    char string;char in[10]={0};
    char word[50000] = {0}; char letter;
    char insert[]={"insert"};
    char delete[]={"delete"};
    char left[]={"left"};
    char right[]={"right"};
    char second[10]={0};
    while(scanf("%s",in)!=EOF){
        if(strcmp(in,insert)==0){
            scanf("%s %c",second, &letter);
            if(strcmp(second,left)==0){
                memmove(word+1,word,strlen(word));
                word[0]=letter;
                }
            else if(strcmp(second,right)==0){
                word[strlen(word)]=letter;
            }
            else{
                int move = calculater(second);
                memmove(word+move-1,word+move-2,strlen(word)-(move-2));
                word[move-1]=letter;
            }
            //free(second);
            
        }
        else if(strcmp(in,delete)==0){
            scanf("%s",second);
            if(strcmp(second,right)==0){
                //printf("dr ");
                memmove(word+strlen(word)-1,word+strlen(word),1);
            }
            else if(strcmp(second,left)==0){
                //printf("dl ");
                memmove(word,word+1,strlen(word));
            }
            else{
                int move=calculater(second);
                memmove(word+(move)-1,word+(move),strlen(word)-move+1);
            }
        }
        //printf("%s\n",word);
    }
    char prev=word[0];int count=0,maxcons=0;
    char maxl[50000]={0};int maxlcount=0;
    for(int c=0;c<strlen(word);c++){
        (word[c]==prev) ? count++ : (count=1);
        //printf("%c %d\n",word[c],count);
        if(count>maxcons){
            maxcons=count;
            maxlcount=1;maxl[0]=word[c];
        }
        else if(count == maxcons){
                maxl[maxlcount]=word[c];
                maxlcount++;
        }
        prev = word[c];
    }
    for(int c=0;c<maxlcount;c++){
        printf("%c ",maxl[c]);
    }
    printf("%d\n",maxcons);
    


    return 0;
}