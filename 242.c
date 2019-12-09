#include<stdio.h>

int main(){
    int a;int x1,y1,r1,x2,y2,r2,r3,x3,y3;
    scanf("%d",&a);
    for(int b=0;b<a;b++){
        int count=0;//printf("%d ",count);
        scanf("%d%d%d%d%d%d%d%d%d",&x1,&y1,&r1,&x2,&y2,&r2,&x3,&y3,&r3);
        int d1,d2,d3=0;
        for(int c=-r1;c<=r1;c++){
            for(int d=-r1;d<=r1;d++){
                
                d1=c*c+d*d;
                if(x1+c-x2>10||x1+c-x2<-10||y1+c-y2>10||y1+c-y2<-10){d2=10000;}
                else{d2=(x1+c-x2)*(x1+c-x2)+(y1+d-y2)*(y1+d-y2);}
                if(x1+c-x3>10||x1+c-x3<-10||y1+c-y3>10||y1+c-y3<-10){d3=10000;}
                else{d3=(x1+c-x3)*(x1+c-x3)+(y1+d-y3)*(y1+d-y3);}
                if((d1<=(r1*r1)&&d2>(r2*r2)&&d3>(r3*r3))||(d1<=(r1*r1)&&d2<=(r2*r2)&&d3<=(r3*r3))){count++;}
                //printf("%d %d %d\n",d1,d2,d3);}
            }
                
               } 
               //printf("%d ",count);
               d1=0;d2=0;d3=0;
        for(int c=-r2;c<=r2;c++){
            for(int d=-r2;d<=r2;d++){
                if(x2+c-x1>10||x2+c-x1<-10||y2+c-y1>10||y2+c-y1<-10){d1=10000;}
                else{d1=(x2+c-x1)*(x2+c-x1)+(y2+d-y1)*(y2+d-y1);}
                d2=c*c+d*d;
                if(x2+c-x3>10||x2+c-x3<-10||y2+c-y3>10||y2+c-y3<-10){d3=10000;}
                else{d3=(x2+c-x3)*(x2+c-x3)+(y2+d-y3)*(y2+d-y3);}
                if(d1>(r1*r1)&&d2<=(r2*r2)&&d3>(r3*r3)){count++;}}
                }
                //printf("%d ",count);
                d1=0;d2=0;d3=0;
        for(int c=-r3;c<=r3;c++){
            for(int d=-r3;d<=r3;d++){
                if(x3+c-x1>10||x3+c-x1<-10||y3+c-y1>10||y3+c-y1<-10){d1=10000;}
                else{d1=(x3+c-x1)*(x3+c-x1)+(y3+d-y1)*(y3+d-y1);}
                if(x3+c-x2>10||x3+c-x2<-10||y3+c-y2>10||y3+c-y2<-10){d2=10000;}
                else{d2=(x3+c-x2)*(x3+c-x2)+(y3+d-y2)*(y3+d-y2);}
                d3=c*c+d*d;
                if(d1>(r1*r1)&&d2>(r2*r2)&&d3<=(r3*r3)){count++;}}
               } //printf("%d ",count);
        printf("%d\n",count);
    }
    return 0;
}

