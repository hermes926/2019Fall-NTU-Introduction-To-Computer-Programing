#include<stdio.h>

int main(){
    int X,Y,x1,y1,x2,y2,dx1,dy1,dx2,dy2,t;
    scanf("%d%d%d%d%d%d%d%d%d%d%d",&X,&Y,&x1,&y1,&x2,&y2,&dx1,&dy1,&dx2,&dy2,&t);
    for(int c=0;c<t;c++){
        x1+=dx1;y1+=dy1;x2+=dx2;y2+=dy2;
        if(x1>X){x1=x1-2;dx1=-dx1;}
        if(x1<1){x1=x1+2;dx1=-dx1;}
        if(x2>X){x2=x2-2;dx2=-dx2;}
        if(x2<1){x2=x2+2;dx2=-dx2;}
        if(y1>Y){y1=y1-2;dy1=-dy1;}
        if(y1<1){y1=y1+2;dy1=-dy1;}
        if(y2>Y){y2=y2-2;dy2=-dy2;}
        if(y2<1){y2=y2+2;dy2=-dy2;}
        
        if(x1==x2&&y1==y2){
            if(dx1+dx2==0){dx1=-dx1;dx2=-dx2;}
            if(dy1+dy2==0){dy1=-dy1;dy2=-dy2;}
        }
        

    }
    printf("%d\n%d\n%d\n%d\n",x1,y1,x2,y2);



    return 0;
}