#include<stdio.h>

int main(){
    int dps[4999],heal[4999],tank[4999];
    for(int c=0;c<4999;c++){
        dps[c]=-1;heal[c]=-1;tank[c]=-1;
    }
    int in=0;int dpsc=0,healc=0,tankc=0;int dpss=0,heals=0,tanks=0;int dpsnow=0,healnow=0,tanknow=0;
    while(scanf("%d",&in)!=EOF){
        switch(in%3){
            case 0:
                dps[dpsc%5000]=in;
                dpsc++;dpsnow++;
                break;
            case 1:
                heal[healc%5000]=in;
                healc++;healnow++;
                break;
            case 2:
                tank[tankc%5000]=in;
                tankc++;tanknow++;
                break;
        }
        if(dpsnow>=3 && healnow >=1 && tanknow >=1){
            printf("%d %d %d %d %d\n",dps[dpss%5000],dps[(dpss+1)%5000],dps[(dpss+2)%5000],heal[heals%5000],tank[tanks%5000]);
            
            dpsnow-=3;
            healnow-=1;
            tanknow-=1;
            dpss+=3;
            heals+=1;
            tanks++;
        }
    }
    
    
    return 0;
}