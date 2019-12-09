#include<stdio.h>
#include<stdbool.h>

int final[16] = {0};
bool off = false;
int minnum = 16;
int min[16] = {0};

void play(bool room[][4],int a,int final[],int finalcount, int minnum, int count, int min[]){
    /*for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            printf("%d ", room[i][j]);
        }
        printf("\n");
    }
    printf("-------\n");*/
    bool room1[4][4]= {0};
    bool room2[4][4]= {0};
    int condition = 0;
    //printf("%d\n", condition);
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            room1[i][j] = room[i][j];
            room2[i][j] = room[i][j];
            if(room[i][j])
                condition++;
        }
    }
    for(int i=finalcount;i<16;i++){
            final[i] = -1;
    }
    //printf("%d\n", condition);
    if(!condition || count == a*a){
        //printf("-\n888-\n");
        if(!condition && minnum > finalcount){
            
            for(int i=0;i<minnum;i++){
                min[i] = final[i];
            }
            minnum = finalcount;
        }
    }
    else{
        play(room2, a, final, finalcount, minnum,count+1, min);
        room1[(int)count/a][count%a] = !(room1[(int)count/a][count%a]);
        room1[(int)count/a + 1][count%a] = !(room1[(int)count/a + 1][count%a]);
        room1[(int)count/a - 1][count%a] = !(room1[(int)count/a - 1][count%a]);
        room1[(int)count/a][count%a + 1] = !(room1[(int)count/a][count%a + 1]);
        room1[(int)count/a][count%a - 1] = !(room1[(int)count/a][count%a - 1]);
        final[finalcount] = count;
        play(room1, a, final, finalcount+1, minnum, count+1, min);
    }
}



int main(){
    int a = 0;
    scanf("%d", &a);
    bool room[4][4] = {0};
    int c;
    while(scanf("%d", &c) != EOF){
        room[(int)c/a][c%a] = true;
    }
    /*for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            printf("%d ", room[i][j]);
        }
        printf("\n");
    }*/
    for(int i=0;i<16;i++){
        final[i] = -1;
        min[i] = -1;
    }
    play(room, a, final, 0, minnum, 0, min);
    for(int i=0;i<minnum;i++){
        printf("%d", min[i]);
        i == minnum-1 ? printf("\n") : printf(" "); 
    }

}