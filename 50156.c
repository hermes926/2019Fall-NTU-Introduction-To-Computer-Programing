#include<stdio.h>
 
int main(){
    int A,B,V,W,X,Y,Z;
    scanf("%d%d%d%d%d%d%d",&A,&B,&V,&W,&X,&Y,&Z);
    float a=A;float b=B;float v=V;float w=W;float x=X;float y=Y;float z=Z;
 
    float p,tp=0; 
    int ans=0;
    if(A%2==0){
        tp=w/a;
        if(tp>p){p=tp;ans=A;}
        tp=v/(a+1);
        if(tp>p){p=tp;ans=A+1;}
            }
    else if(A%2==1){
        tp=w/(a+1);
        if(tp>p){p=tp;ans=A+1;}
        tp=v/a;
        if(tp>p){p=tp;ans=A;}
    }
 
    if(B%3==0){
        tp=x/b;if(tp>p){p=tp;ans=B;}
        tp=y/(b+1);if(tp>p){p=tp;ans=B+1;}
        tp=z/(b+2);if(tp>p){p=tp;ans=B+2;}
    }
    else if(B%3==1){
        tp=x/(b+2);if(tp>p){p=tp;ans=B+2;}
        tp=y/b;if(tp>p){p=tp;ans=B;}
        tp=z/(b+1);if(tp>p){p=tp;ans=B+1;}    
    }
    else if(B%3==2){
        tp=x/(b+1);if(tp>p){p=tp;ans=B+1;}
        tp=y/(b+2);if(tp>p){p=tp;ans=B+2;}
        tp=z/b;if(tp>p){p=tp;ans=B;}
    }
 
    if(ans==0){ans=1;
    }
 
    printf("%d\n",ans);
    return 0;
}