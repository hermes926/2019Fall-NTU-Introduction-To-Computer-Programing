#include<stdio.h>

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n],b[m][3];
    for(int c=0;c<n;c++){scanf("%d",&a[c]);}

    for(int c=0;c<m;c++){b[c][0]=0;b[c][1]=0;b[c][2]=10000;}
    for(int c=0;c<n;c++){
        b[a[c]%m][0]=b[a[c]%m][0]+a[c];
        if(a[c]>b[a[c]%m][1]){b[a[c]%m][1]=a[c];}
        if(a[c]<b[a[c]%m][2]){b[a[c]%m][2]=a[c];}
    }
    for(int c=0;c<m;c++){
        printf("%d %d %d\n",b[c][0],b[c][1],b[c][2]);
    }
    return 0;
}