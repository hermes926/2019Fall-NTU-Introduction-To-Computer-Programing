#include<stdio.h>
#include<string.h>

int main(){
    int n=0;
    scanf("%d",&n);
    char s[256];int ncount=0;char ts[128][256]={};int wcount=0;int tn=n;
    while(scanf("%s",s)!=EOF){
        if(ncount+strlen(s)<=n){
            strcpy(ts[wcount],s);
            //printf("%s %s\n",ts[0],ts[1]);
            wcount++;
            ncount+=(strlen(s)+1);
        }
        else{
            if(wcount==1){
                printf("%s",ts[0]);
                for(int c=0;c<n-strlen(ts[0]);c++){
                    printf(" ");
                }
            }
            else{    
                for(int c=0;c<wcount;c++){
                    tn-=strlen(ts[c]);
                }
                for(int c=0;c<wcount;c++){
                    printf("%s",ts[c]);
                    
                    if(c!=wcount-1){
                    for(int d=0;d<tn/(wcount-1);d++)
                        printf(" ");
                    if(c<tn%(wcount-1)){
                        printf(" ");
                    }
            }}}
            printf("\n");
            memset(ts,0,sizeof(ts));
            //printf("%s ",s);
            strcpy(ts[0],s);
            //printf("%s ",ts[0]);
            
            wcount=1;tn=n;ncount=(strlen(s)+1);
        }
    }
    if(wcount==1){
                printf("%s",ts[0]);
                for(int c=0;c<n-strlen(ts[0]);c++){
                    printf(" ");
                }
            }
            else{    
                for(int c=0;c<wcount;c++){
                    tn-=strlen(ts[c]);
                }
                for(int c=0;c<wcount;c++){
                    printf("%s",ts[c]);
                    
                    if(c!=wcount-1){
                    for(int d=0;d<tn/(wcount-1);d++)
                        printf(" ");
                    if(c<tn%(wcount-1)){
                        printf(" ");
                    }
    }}}
    printf("\n");
    
    return 0;
}