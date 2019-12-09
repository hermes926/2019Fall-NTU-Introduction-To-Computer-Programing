#include<stdio.h>

int try(int in[], int N,int tar){
    int tar1 = tar - in[0];
    int final=0;
    if((N==1 && tar1 !=0) || N==0){
        return 0;
    }
    
    else{
        
        int re1[N-1];
        for(int c=0;c<N-1;c++){
            re1[c]=in[c+1];
        }
        final += (tar1 == 0 ? 1 : try(re1, N-1, tar1));
        //final += try(re1, N-1, tar1);
        final += try(re1, N-1, tar);
        return final;
    }
    
}

int main(){
    int n;
    scanf("%d", &n);int set[15];
    for(int c=0;c<n;c++){
        scanf("%d", &set[c]);
    }
    int z;
    while(scanf("%d", &z)!=EOF){
        int out = try(set, n, z);
        printf("%d\n", out);
    }
    
    
    return 0;
}