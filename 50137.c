#include<stdio.h>
#include<stdbool.h>

struct rectangle{
    int w;
    int l;
};

typedef struct rectangle rec;
void maxindex(rec in[], int n, rec now, int times, int indexcount, int indexsum,bool con){
    static int maxcount = 0;
    static int maxin = 0;
    //printf("%d %d %d\n", now.w, now.l, indexcount);
    if(con && times < n){
        maxindex(in, n, now, times+1, indexcount, indexsum, true);
        if(in[times].w <= now.w && in[times].l <= now.l){
            
            indexcount++;indexsum += times;
            if(indexcount > maxcount || (indexcount == maxcount && maxin < indexsum)){
                maxin = indexsum;maxcount = indexcount;
            }
            maxindex(in, n, in[times], times+1, indexcount, indexsum, true);
        }
        else if(in[times].l <= now.w && in[times].w <= now.l){
            indexcount++;indexsum += times;
            if(indexcount > maxcount || (indexcount == maxcount && maxin < times)){
                maxin = indexsum;maxcount = indexcount;
            }
            maxindex(in, n, in[times], times+1, indexcount, indexsum, true);
        }
    }
    else if(!con){
        printf("%d %d\n", maxcount, maxin);
    }
}

int main(){
    int n;bool con = true;
    scanf("%d", &n);
    rec in[n];rec ini = {10000, 10000};
    for(int i=0;i<n;i++)
        scanf("%d%d", &in[i].w, &in[i].l);
    maxindex(in, n, ini, 0, 0, 0,true);
    maxindex(in, n, ini, 0 ,0, 0,false);

    return 0;
}