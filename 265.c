#include<stdio.h>

int main(){
    int x,y,maxx,maxy,minx,miny;int count=0;
    while(scanf("%d%d",&x,&y)!=EOF){
        if(count==0){maxx=x;maxy=y;minx=x;miny=y;}
        else{
            if(x>maxx){maxx=x;}
            if(x<minx){minx=x;}
            if(y>maxy){maxy=y;}
            if(y<miny){miny=y;}
        }
        count++;
    }
    int area=(maxx-minx)*(maxy-miny);
    printf("%d\n",area);
    return 0;
}