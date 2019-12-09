#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<assert.h>
#include<stdbool.h>

int main(){
    char a[32], b[32], out[32];
    uint8_t f1[100000] = {0}, f2[100000] = {0};
    scanf("%s%s", a, b);
    scanf("%s", out);
    FILE *fp1 = fopen (a, "rb");
    assert(fp1 != NULL);
    FILE *fp2 = fopen (b, "rb");
    assert(fp2 != NULL);
    int i = 0, j = 0;char z;
    while((z = fgetc(fp1)) != EOF){
        f1[i] = z;
        //printf("%d ", f1[i]);
        i ++;
    }
    while((z = fgetc(fp2)) != EOF){
        f2[j] = z;
        //printf("%d ", f2[j]);
        j ++;
    }
    /*for(int c = 0;c < i;c++)
        printf("%d ", f1[c]);
    printf("\n");
    for(int c = 0;c<j;c++)
        printf("%d ", f2[c]);
    printf("\n");*/
    fclose(fp1);
    fclose(fp2);
    int c = 1;int carry = 0;
    uint8_t final[100000];
    if(j > i){
        while(c <= i){
            final[j-c] = (f2[j-c] + f1[i-c] + carry) % 256 ;
            carry = (f2[j-c] + f1[i-c] + carry) >= 256 ?  1 :  0;
            c ++;
        }
        while(c <= j){
            final[j-c] = (f2[j-c] + carry) % 256 ;
            carry = ((f2[j-c] + carry) >= 256 ? 1 : 0);
            c ++;
        }
    }
    else{
        while(c <= j){
            final[i-c] = (f2[j-c] + f1[i-c] + carry) % 256 ;
           carry = (f2[j-c] + f1[i-c] + carry) >= 256 ?  1 :  0;
            c ++;
        }
        while(c <= i){
            final[i-c] = (f1[i-c] + carry) % 256 ;
            carry = ((f1[i-c] + carry) >= 256 ? 1 : 0);
            c ++;
        }
    }
    
    FILE *fp3 = fopen(out, "wb");
    assert(fp3 != NULL);
    /*for(int d=0;d<c-1;d++)
        printf("%d ", final[d]);*/
    fwrite(final, sizeof(uint8_t), c-1, fp3);
    







    return 0;
}