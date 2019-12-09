#include<stdio.h>

void func(int n, int in[n], int N,int store[N-1]){
    if(n==1){
        for(int c=0;c<N-1;c++){
            printf("%d ",store[c]);
        }
        printf("%d\n", in[0]);
    }
    else{
    int in1[n][n-1];
    for(int c=0;c<n;c++){
        int e=0;
        for(int d=0;d<n;d++){
            if(d==c){continue;}
            in1[c][e]=in[d];
            e++;
        }
        //printf("%d ",in[c]);
        store[N-n]=in[c];
        func(n-1, in1[c], N, store);

    }}
}

int main(){
    int N=0;
    scanf("%d",&N);
    int a[N];
    for(int c=0;c<N;c++){
        scanf("%d", &a[c]);
    }
    int t=0;
    for(int c=0;c<N;c++){
        for(int d=0;d<c;d++){
            if(a[c]<a[d]){
                t=a[c];a[c]=a[d];a[d]=t;
            }
        }
    }
    /*for(int c=0;c<N;c++){
        printf("%d ",a[c]);
    }*/
    int store[N-1];
    for(int c=0;c<N-1;c++){
        store[c]=0;
    }
    func(N, a, N, store);
    
    return 0;
}