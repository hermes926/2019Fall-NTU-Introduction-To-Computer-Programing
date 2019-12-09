#include<stdio.h>
#include<string.h>
 
int main(){
    char result[100010]={};
    char in[100010]={};
    int rcount=0;
    scanf("%s",result);
    
    while(scanf("%s",in)!=EOF){
        //printf("%s ",in);
        rcount=0;int prevrlen=strlen(result);
        
        for(int c=0;(c<strlen(in) && rcount<strlen(result));){
            if(in[c]<result[rcount] || (in[c]==result[rcount] && in[c+1]<result[rcount+1]) || (in[c]==result[rcount] && in[c+1]==result[rcount+1] && in[c+2]<result[rcount+2])){
                
                for(int d=strlen(result)+2;d>=rcount+3;d--)
                    result[d]=result[d-3];
                result[rcount]=in[c];result[rcount+1]=in[c+1];result[rcount+2]=in[c+2];
                c+=3;
 
            }
            rcount+=3;
            //printf("%d %d %d\n",strlen(result),strlen(in),c);
        }
        
        while(0<prevrlen+strlen(in)-strlen(result)){
            result[strlen(result)]=in[strlen(result)-prevrlen];
        }
        printf("%s\n",result);
 
    }
 
    return 0;
}