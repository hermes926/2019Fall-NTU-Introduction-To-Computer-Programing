#include<stdio.h>

int onecount(unsigned char enter){
    int numcount = 0;
    for(int k=0;k<8;k++){
        if((enter >> k) % 2 == 1)
            numcount ++;
    }
    return numcount;
}

int main(){
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    unsigned char valid[25];
    unsigned long long int lar[5];
    int j=0;
    for(int i=0;i<m;i++){
        scanf("%lld", &lar[i]);
        while(j < n){
            valid[j] = (lar[i] >> (8*(7 - j%8))) % 256;
            j++;
            if( j % 8 == 0 )
                break;
        }
    }
    /*for(int i=0;i<n;i++)
        printf("%hhu\n", valid[i]);
    printf("----------");*/
    unsigned char in;
    int z = p;
    while(scanf("%hhu", &in)!=EOF){
        
        for(int j=0;j<n;j++){
            //printf("%d ", onecount(in ^ valid[j]));
            
            if( in == valid[j] || onecount(in ^ valid[j]) == 1){
                printf("%hhu\n", valid[j]);
                break;
            }
        }
    }

    return 0;
}