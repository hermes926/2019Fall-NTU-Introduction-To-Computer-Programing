#include<stdio.h>
#include<stdbool.h>
 
int main(){
    int a;
    int anwser=0;int con=0,tc=0,ptc=1,pa=0,maxl=0;int count=0, maxleftl=0,fi=0;
    while(scanf("%d",&a)!=EOF){
        if(count==0){pa=a;count=1;}
        else if(count==1){
            tc++;count++;
            if(pa>a){con=-1;}
            else{con=1;}
            pa=a;
        }
        else{
            count++;
            if(con==1&&a>pa){
                tc++;
            }
            else if(con==-1&&a>pa){
                if(ptc+tc+1>maxl){maxl=ptc+tc+1;fi=count-maxl;maxleftl=ptc;if(fi==0){fi=1;}}
                else if(ptc+tc+1==maxl&&ptc>maxleftl){maxl=ptc+tc+1;fi=count-maxl;maxleftl=ptc;if(fi==0){fi=1;}}
                ptc=tc;tc=1;con=1;
            }
            if(con==-1&&a<pa){
                tc++;
            }
            else if(con==1&&a<pa){
                if(ptc+tc+1>maxl){maxl=ptc+tc+1;fi=count-maxl;maxleftl=ptc;if(fi==0){fi=1;}}
                else if(ptc+tc+1==maxl&&ptc>maxleftl){maxl=ptc+tc+1;fi=count-maxl;maxleftl=ptc;if(fi==0){fi=1;}}
                ptc=tc;tc=1;con=-1;
            }
            pa=a;
        }
        //printf("%d %d %d %d\n",tc,ptc,maxl,fi);
    }
    if(ptc+tc+1>maxl&&fi!=0){maxl=ptc+tc+1;fi=count-maxl+1;if(fi==0){fi=1;}}
    else if(ptc+tc+1==maxl&&ptc>maxleftl&&fi!=0){maxl=ptc+tc+1;fi=count-maxl+1;if(fi==0){fi=1;}}
    if(fi==0){printf("0\n");}
    else{
 
    printf("%d %d\n",maxl, fi);}
    return 0;
}