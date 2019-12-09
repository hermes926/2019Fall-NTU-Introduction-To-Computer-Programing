#include<stdio.h>

void final(int num[],int n, int k, int m, int step, int sum, int *anw, int con){
    //printf("%d %d --",step,sum);
    if(step >= k && sum <= m && con==1){
        (*anw)++;//printf("%d %d\n",step,sum);
    }
    if(m >= sum && n >=1){
        int next[n-1];int d=0;
        for(int c=0;c<n-1;c++){
            next[c]=num[c+1];
        }
        final(next, n-1, k, m, step+1, sum+num[0], anw, 1);
        final(next, n-1, k, m, step, sum, anw, 0);
    }
}

int main(){
    int k, n, m;int star = 0;int *fin= &star;
    scanf("%d%d%d", &k, &n, &m);
    int arr[n];
    for(int c=0;c<n;c++){
        scanf("%d", &arr[c]);
    }
    final(arr, n, k, m, 0, 0, fin, 0);
    printf("%d\n",*fin);
    return 0;
}