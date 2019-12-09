#include<stdio.h>
#include<stdbool.h>

int minecount(int out[9][9], int x, int y){
    int final = 0;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if( x+i >= 0 && x+i < 9 &&  y+j >= 0 && y+j < 9 && out[x+i][y+j] == 1)
                final ++;
        }
    }
    return final;
}

int main(){
    bool found = false;
    int in[9][9];
    int out[9][9];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%d", &in[i][j]);
            out[i][j] = 0;
        }
    }
    /*for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            j != 8 ? printf("%d ", out[i][j]) : printf("%d\n", out[i][j]);
        }
    }*/
    int count = 0;
    while(!found){
        found = true;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                //printf("%d ", minecount(out, i, j));
                if(minecount(out, i, j) == in[i][j])
                    out[i+1][j+1] = 0;
                else if(minecount(out, i, j) == in[i][j] - 1)
                    out[i+1][j+1] = 1;
                else{
                    found = false; break;
                }
            }
            //printf("\n");
            if(!found)
                break;
        }
        if(found){
            for(int i=0;i<9;i++){
                if(minecount(out, i, 8) != in[i][8] || minecount(out, 8, i) != in[8][i]){
                    found = false;break;
        }}}
        int x = 0,y = 0;
        if(!found){
            /*for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                j != 8 ? printf("%d ", out[i][j]) : printf("%d\n", out[i][j]);
                }
            }
            printf("----------\n");*/
            for(int i=1;i<9;i++){
                for(int j=1;j<9;j++){
                    out[i][j] = 0;
                }
            }
            while(out[x][y] == 1){
                out[x][y] = 0;
                if(x == 0){
                    y++;
                    if(y == 9){
                        y=0;x++;
                    }
                }
                else{
                    x++;
                    if(x == 9)
                        break;
                }   
            }
            if(x == 9)
                break;
            out[x][y] = 1;
        }
        
    }
    if(found) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                j != 8 ? printf("%d ", out[i][j]) : printf("%d\n", out[i][j]);
            }
        }
    }
    else{
        printf("no solution\n");
    }

    return 0;
}