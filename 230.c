#include<stdio.h>

void maxfunc(int load, int n, int item[][2],int value, int *fin){
        if(*fin < value){
        *fin = value;
    }
    if(n==1 && load >= item[0][0]){
        value+= item[0][1];
        if(*fin < value){
        *fin = value;
    }
    }
    else if(n>=2){
        int next[n-1][2];int d=0;
        for(int c=0;c<n;c++){
            if(c==d){continue;}
            else{
                next[d][0]=item[c][0];
                next[d][1]=item[c][1];
                d++;
            }
        }
        if(load >= item[0][0]){
            maxfunc(load-item[0][0], n-1, next, value+item[0][1], fin);
        }
        maxfunc(load, n-1, next, value, fin);
    }
}

int main(){
    int n,w;int final=0;
    scanf("%d%d", &n, &w);
    int object[n][2];
    for(int c=0;c<n;c++){
        scanf("%d%d", &object[c][0], &object[c][1]);
    }
    int *fin = &final;
    maxfunc(w, n, object, 0, fin);
    printf("%d\n",final);
    return 0;
}