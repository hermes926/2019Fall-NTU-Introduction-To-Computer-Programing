#include<stdio.h>
#include<string.h>


int main(){
    int n;
    scanf("%d",&n);char name[n][12][70];int ingren[n];
    for(int c=0;c<n;c++){
        scanf("%s%d",name[c][0],&ingren[c]);
        //printf("%d ",strlen(name[c][0]));
        //printf("%s %d",name[c][0],ingren[c]);
        for(int d=1;d<=ingren[c];d++){
            scanf("%s",name[c][d]);
            //printf("%d ",strlen(name[c][d]));

        }
    }
    int m;
    scanf("%d",&m);
    for(int c=0;c<m;c++){
        char coms1[70],coms2[70];
        scanf("%s%s",coms1,coms2);
        int s1=-1,s2=-1;
        for(int d=0;d<n;d++){
            if(strcmp(name[d][0],coms1)==0){
                s1=d;
            }
            if(strcmp(name[d][0],coms2)==0){
                s2=d;
            }
        }
        //printf("%d %d",s1,s2);
        char output[12][70]={0};int fcount=0;
        for(int d=1;d<=ingren[s1];d++){
            for(int e=1;e<=ingren[s2];e++){
                if(strcmp(name[s1][d],name[s2][e])==0){
                    strcpy(output[fcount],name[s1][d]);fcount++;
                }
            }
        }
        if(fcount==0){
            printf("nothing\n");
        }
        else{
            for(int d=0;d<fcount;d++){
                for(int e=0;e<d;e++){
                    char temp[70]={0};
                    if(strcmp(output[d],output[e])<0){
                        strcpy(temp,output[d]);strcpy(output[d],output[e]);strcpy(output[e],temp);
                    }
                }
            }
            for(int d=0;d<fcount;d++){
                (d==fcount-1)?printf("%s\n",output[d]):printf("%s ",output[d]);
            }
        }
    }

    
    
    return 0;
}