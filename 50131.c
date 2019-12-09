#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(){
    char in[10010]={0};int i=0,j=0;int count=1,sicount=0,prevsi=0;
    int istart=0,iend=0,jstart=0,jend=0;bool icon,jcon;
    while(scanf("%s %d %d",in,&i,&j)!=EOF){
        count=0;sicount=0;prevsi=-1;icon=false;jcon=false;
        while(count<strlen(in)){
            switch(*(in+count)){
                case 'a': case 'e': case 'i': case 'o': case 'u':
                    if(sicount == i ){
                        icon=true;
                        istart=prevsi+1;iend=count;
                    }
                    else if(sicount == j){
                        jcon=true;
                        jstart=prevsi+1;jend=count;
                    }
                    prevsi=count;
                    sicount++;break;     
            }
            count++;
            if(icon && jcon){
                break;
            }
        }
        if(!icon){
            istart=prevsi+1;iend=strlen(in)-1;
        }
        else if(!jcon){
            jstart=prevsi+1;jend=strlen(in)-1;
        }
        for(int c=0;c<strlen(in);c++){
            (c<=iend && c>=istart) ? printf("%c",*(in+c)) : printf("+");
        }
        printf("\n");
        for(int c=0;c<strlen(in);c++){
            (c<=jend && c>=jstart) ? printf("%c",*(in+c)) : printf("+");
        }
        printf("\n");
        for(int c=0;c<strlen(in);c++){
            (!(c<=iend && c>=istart) && !(c<=jend && c>=jstart)) ? printf("%c",*(in+c)) : printf("+");
        }
        printf("\n"); 
        in[0]='\0';
    }
    return 0;
}