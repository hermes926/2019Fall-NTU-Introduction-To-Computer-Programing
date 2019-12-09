#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdint.h>

int main(){
    char in[200]; 
    scanf("%s", in);
    FILE *fp = fopen(in, "rb");
    assert(fp != NULL);
    int x;
    
    fread(&x, sizeof(int), 1, fp);
    int16_t iden[x];
    fread(iden, sizeof(int16_t), x, fp);
    int save[80000]={0};
    //printf("%d\n%d\n", iden[0], iden[1]);
    //printf("%d\n", x);
    for(int i=0;i<x;i++){
        save[iden[i] + 40000] ++;
        //printf("%d ", iden[i]);
    }
    //printf("\n--%d--%d\n", save[40010]);
    int max = 0;int maxnum = -1;
    for(int i = 79999;i >= 0; i--){
        if(save[i] > max){
            max = save[i];
            maxnum = i-40000;
        }
    }
    fclose(fp);
    printf("%d\n%d\n", maxnum, max);
    

    return 0;
}