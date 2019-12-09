#include<stdio.h>

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int house[b+2][a+2];
    for(int c=0;c<=b+1;c++){
        for(int d=0;d<=a+1;d++){
            if(c==0||d==0||c==b+1||d==a+1){
                house[c][d]=2;
            }
            else{
                scanf("%d",&house[c][d]);
            }}}  
    
    for(int c=1;c<=b;c++){
        int con=0,d=1,e=0,direction=0;
        while(house[c+e][d]>=0&&house[c+e][d]<=1){
            if(direction==0&&house[c+e][d]==0){
                d++;
            }
            else if(direction==0&&house[c+e][d]==1){
                e-=1;direction=1;
            }
            else if(direction==1&&house[c+e][d]==1){
                d++;direction=0;
            }
            else if(direction==1&&house[c+e][d]==0){
                e-=1;
            }
        }
        if(c+e==0){house[0][d]=-(2*a+b+c-1);}
        else if(d==a+1){house[c+e][a+1]=-(2*a+b+c-1);}}
    
    for(int c=1;c<=b;c++){
        int con=0,d=a,e=0,direction=0;
        while(house[c+e][d]>=0&&house[c+e][d]<=1){
            if(direction==0&&house[c+e][d]==0){
                d-=1;
            }
            else if(direction==0&&house[c+e][d]==1){
                e++;direction=1;
            }
            else if(direction==1&&house[c+e][d]==1){
                d-=1;direction=0;
            }
            else if(direction==1&&house[c+e][d]==0){
                e++;
            }
        }
        if(c+e==b+1){house[b+1][d]=-(a+b-c);}
        else{house[c+e][0]=-(a+b-c);}}

    for(int c=1;c<=a;c++){
        int d=b,e=0,direction=0;
        while(house[d][c+e]>=0&&house[d][c+e]<=1){
            if(direction==0&&house[d][c+e]==0){
                d-=1;
            }
            else if(direction==0&&house[d][c+e]==1){
                e++;direction=1;
            }
            else if(direction==1&&house[d][c+e]==1){
                d-=1;direction=0;
            }
            else if(direction==1&&house[d][c+e]==0){
                e++;
            }
        }
        if(c+e==a+1){house[d][a+1]=(-c+1);}
        else{house[0][c+e]=-c+1;}}

    for(int c=1;c<=a;c++){
        int d=1,e=0,direction=0;
        while(house[d][c+e]>=0&&house[d][c+e]<=1){
            if(direction==0&&house[d][c+e]==0){
                d++;
            }
            else if(direction==0&&house[d][c+e]==1){
                e-=1;direction=1;
            }
            else if(direction==1&&house[d][c+e]==1){
                d++;direction=0;
            }
            else if(direction==1&&house[d][c+e]==0){
                e-=1;
            }
        }
        if(c+e==0){house[d][0]=-(2*a+b-c);}
        else if(d==b+1){house[b+1][c+e]=-(2*a+b-c);}}

        /*for(int c=0;c<=b+1;c++){
        for(int d=0;d<=a+1;d++){
            printf("%3d ",house[c][d]);}
            printf("\n");}*/
        
        for(int c=1;c<=a;c++){printf("%d\n",-house[b+1][c]);        }
        for(int c=1;c<=b;c++){printf("%d\n",-house[b-c+1][a+1]);        }

        for(int c=1;c<=a;c++){printf("%d\n",-house[0][a-c+1]);        }
        for(int c=1;c<=b;c++){printf("%d\n",-house[c][0]);        }
    
      
    

    return 0;
}