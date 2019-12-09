#include <stdio.h>
int hasEOF = 0;
int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;    
        }
        p = buf;
    }
    return *p++;
}
int ReadInt(int *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}
int main() {
    int book;long long int shelf=0;
    while (ReadInt(&book)) {
        int con=0;int z=0;
        long long int tshelf=shelf;
        for(z=0;z<8;z++){
            if((tshelf >> (z*8))%256 == book){
                con=1;break;
            }
        }
        if(con==0){
            shelf = shelf << 8;
            shelf += book;
        }
        else{
            long long int multi=1;
            for(int c=0;c<z;c++){
                multi*=256;
            }
            shelf -= book*multi;
            shelf += (tshelf%multi)*255;
            shelf += book;
        }
    }    
    for(int c=7;c>=0;c-=1){
            int num=(shelf >> 8*c)%256;
            c==0?printf("%d\n",num):printf("%d ",num);
    }
    // output your answer
    return 0;
}