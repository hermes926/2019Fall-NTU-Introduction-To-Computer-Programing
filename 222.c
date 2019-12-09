#include<stdio.h>

int main(){
    long long int shelf=0;
    int book;
    while(scanf("%d",&book)!=EOF){
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
     
    
    return 0;
}