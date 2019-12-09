#include<stdio.h>

int main(){
    int s1,s2,s3,f1,f2,f3;
    scanf("%d%d%d%d%d%d",&s1,&s2,&s3,&f1,&f2,&f3);
    int yn,money=0;
    while(scanf("%d",&yn)!=EOF){
        if(yn==s1||yn==s2||yn==s3){
            money+=2000000;
        }
        //printf("%d\n",money);
        if(yn%1000==f1%1000){
            money+=200;
            if(yn%10000==f1%10000){
                money+=800;
                if(yn%100000==f1%100000){
                    money+=3000;
                    if(yn%1000000==f1%1000000){
                        money+=6000;
                        if(yn%10000000==f1%10000000){
                            money+=30000;
                            if(yn==f1){
                                money+=160000;}}} }}}
        //printf("%d\n",money);
        if(yn%1000==f2%1000){
            money+=200;
            if(yn%10000==f2%10000){
                money+=800;
                if(yn%100000==f2%100000){
                    money+=3000;
                    if(yn%1000000==f2%1000000){
                        money+=6000;
                        if(yn%10000000==f2%10000000){
                            money+=30000;
                            if(yn==f2){
                                money+=160000;}}} }}}
        //printf("%d\n",money);
        if(yn%1000==f3%1000){
            money+=200;
            if(yn%10000==f3%10000){
                money+=800;
                if(yn%100000==f3%100000){
                    money+=3000;
                    if(yn%1000000==f3%1000000){
                        money+=6000;
                        if(yn%10000000==f3%10000000){
                            money+=30000;
                            if(yn==f3){
                                money+=160000;}}} }}}
                                //printf("%d\n",money);
    }

    printf("%d\n",money);
    
    
    return 0;
}