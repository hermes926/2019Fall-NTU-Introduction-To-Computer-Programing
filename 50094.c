#include<stdio.h>
#include<string.h>

int main(){
    int threshold;
    scanf("%d", &threshold);
    char word[100];int map[26][26]={0};
    while(scanf("%s", word)!=EOF){
        for(int i=0;i<strlen(word);i++){
            if(i >= 1){
                map[word[i-1] - 97][word[i] - 97]++;
            }
        }
    }
    for(int i = 0; i<26;i++){
        for(int j=0;j<26;j++){
            j == 25 ? printf("%d\n", map[i][j]) : printf("%d ",map[i][j]);
        }
    }
    int maxcol[26]={0} ;int tmax=0;
    for(int i = 0; i < 26; i ++ ){
        tmax=0;
        for(int j = 0; j < 26; j++){
            if(map[i][j] > tmax)
                tmax = map[i][j];
        }
        maxcol[i] = tmax;
    }
    int final[26]={0};int lettercount=0;
    for(int i=0;i<26;i++){
        if(maxcol[i] > threshold){
            final[lettercount] = i;
            lettercount++;
        }
    }
    for(int i=1;i<lettercount;i++){
        int tt=0;
        for(int j=0;j<i;j++){
            if(maxcol[final[i]] > maxcol[final[j]]){
              tt = final[i];final[i]=final[j];final[j]=tt;  
            }
        }
    }
    for(int i=0;i<lettercount;i++){
        printf("%c", final[i]+97);
    }
    printf("\n");

}