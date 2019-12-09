#include<stdio.h>

int area(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
    int dx=0,dy=0,ux=0,uy=0,area=0;
    if(x2 > x3 && y2 > y3 && x4 > x1 && y4 > y1){
        ux = (x2>x4)? x4 : x2;
        uy = (y2>y4)? y4 : y2;
        dx = (x1>x3)? x1 : x3;
        dy = (y1>y3)? y1 : y3;
    }
    area=(ux-dx)*(uy-dy);
        return area;   
}

int main(){
    int xad,yad,xau,yau,xbd,ybd,xbu,ybu,xcd,ycd,xcu,ycu;int farea=0;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&xad,&yad,&xau,&yau,&xbd,&ybd,&xbu,&ybu,&xcd,&ycd,&xcu,&ycu);
    farea+=(xau-xad)*(yau-yad);farea+=(xbu-xbd)*(ybu-ybd);farea+=(xcu-xcd)*(ycu-ycd);
    //printf("%d\n",farea);
    farea-=area(xad,yad,xau,yau,xbd,ybd,xbu,ybu);
    farea-=area(xad,yad,xau,yau,xcd,ycd,xcu,ycu);
    farea-=area(xcd,ycd,xcu,ycu,xbd,ybd,xbu,ybu);
    //printf("%d\n",farea);
    int dx=0,dy=0,ux=0,uy=0;
    if(area(xad,yad,xau,yau,xbd,ybd,xbu,ybu)>0){
        ux = (xau>xbu)? xbu : xau;
        uy = (yau>ybu)? ybu : yau;
        dx = (xad>xbd)? xad : xbd;
        dy = (yad>ybd)? yad : ybd;
    }
    //printf("%d %d %d %d\n",ux,uy,dx,dy);
    farea+=area(dx,dy,ux,uy,xcd,ycd,xcu,ycu);
    printf("%d\n",farea);
return 0;
}