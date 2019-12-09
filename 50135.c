#include<stdio.h>

int main(){
    int a,b;char in[100000]={0};
    scanf("%d",&a);
    switch(a){
        case 0:
            scanf("%s", in);
            int c=0;unsigned long long int ch=0, a=0;
            while(in[c]!='\0'){
                ch = in[c];
                //printf("%lld ",ch) ;
                ch = ch << (8*(8 - (c % 8) - 1));
                //printf("%lld ",ch);
                a += ch;
                if(c % 8 == 7){
                    printf("%lld\n", a);
                    a=0;
                }
                c++;
            }
            printf("%lld\n", a);break;
        case 1:
            scanf("%d", &b);
            unsigned long long int inp=0;
            for(int i=0;i<b;i++){
                scanf("%lld", &inp);
                for(int j=7;j>=0;j--){
                    //printf("%d", (inp >> (j*8)) % 256);
                    char o = (inp >> (j*8)) % 256;
                    if(o == 0) 
                        break;
                    else
                        printf("%c", o);
                }
            }
            printf("\n");
            break;


    }


    return 0;
}