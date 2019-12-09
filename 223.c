#include<stdio.h>

void print(int direction, int x, int y, int power){
    if(power > 0){
        int minus = 1;
        for(int i=0;i<power-1;i++)
            minus = minus * 2;
        //printf("%d" , minus);
        switch(direction){
            case 1:
                print(1, x, y, power-1);
                print(1, x-minus, y-minus, power-1);
                print(2, x+minus, y-minus, power-1);
                print(4, x-minus, y+minus, power-1);
                break;
            case 2:
                print(2, x, y, power-1);
                print(2, x+minus, y-minus, power-1);
                print(1, x-minus, y-minus, power-1);
                print(3, x+minus, y+minus, power-1);
                break;
            case 3:
                print(3, x, y, power-1);
                print(3, x+minus, y+minus, power-1);
                print(2, x+minus, y-minus, power-1);
                print(4, x-minus, y+minus, power-1);
                break;
            case 4:
                print(4, x, y, power-1);
                print(4, x-minus, y+minus, power-1);
                print(1, x-minus, y-minus, power-1);
                print(3, x+minus, y+minus, power-1);
                break;     
        }
    }
    else{
        printf("%d %d %d\n", direction, x, y);
    }
}

int main(){
    int l,m;int powerl = 0;int powerm = 0;
    scanf("%d%d", &l, &m);
    int tl = l;int tm = m;
    while(tl != 1){
        powerl++;
        tl /= 2;
    }
    while(tm != 1){
        powerm++;
        tm /= 2;
    }
    tm = m;
    for(int i=0;i<powerl-powerm;i++){
        //printf("%d %d %d %d\n----\n", l ,m, powerl, powerm);
        print(1, l-tm, l-tm, powerm+i);
        tm *= 2;
    }
        

    return 0;
}