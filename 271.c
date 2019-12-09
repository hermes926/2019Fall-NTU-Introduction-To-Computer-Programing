#include<stdio.h>

int main(){
    int a,b;
    scanf("%d",&a);
    int f[a];
    for(int c=a-1;c>=0;c=c-1){scanf("%d",&f[c]);}
    scanf("%d",&b);
    int g[b];
    for(int c=b-1;c>=0;c=c-1){scanf("%d",&g[c]);}
    int h[a+b-1];
    for(int c=a+b-2;c>=0;c=c-1){
        h[c]=0;
        for(int d=0;d<=c;d++){
            if(d>=0&&d<=a-1&&(c-d)>=0&&(c-d)<=b-1){h[c]=h[c]+f[d]*g[c-d];}
        }
        if(c==0){printf("%d\n",h[c]);}
        else{printf("%d ",h[c]);}
    }
    return 0;
}
