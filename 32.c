#include<stdio.h>

int main(){
    int a[100];int count=0,x=0;
    while(scanf("%d",&x)!=EOF){
        a[count]=x;
        count++;
        
    }
    for(int z=0;z<count;z++){
        int d=1,maxz=0;int maxp,p=1;
        while(z-d>=0&&z+d<count&&a[z-d]==a[z+d]){
            p+=2;d++;
            if(p>=maxp){maxp=p;maxz=z;}
        }
    }



    return 0;
}