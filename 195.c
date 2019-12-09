#include<stdio.h>

int main(){
    int board[3][3];
    for(int a=0;a<3;a++){for(int b=0;b<3;b++){board[a][b]=0;}}
    int x,y;int con=0;int play=0;
    int n=0;scanf("%d",&n);
    for(int c=0;c<n;c++){scanf("%d%d",&x,&y);
        if(x>2||y>2||x<0||y<0||board[x][y]!=0){continue;}
        else{
            if(play==0){board[x][y]=1;play=1;}
            else{board[x][y]=-1;play=0;}
            
            if(board[0][0]==1&&board[0][1]==1&&board[0][2]==1){printf("Black wins.\n");con=1;break;}
            else if(board[1][0]==1&&board[1][1]==1&&board[1][2]==1){printf("Black wins.\n");con=1;break;}
            else if(board[0][0]==1&&board[1][0]==1&&board[2][0]==1){printf("Black wins.\n");con=1;break;}
            else if(board[2][0]==1&&board[2][1]==1&&board[2][2]==1){printf("Black wins.\n");con=1;break;}
            else if(board[0][1]==1&&board[1][1]==1&&board[2][1]==1){printf("Black wins.\n");con=1;break;}
            else if(board[0][2]==1&&board[1][2]==1&&board[2][2]==1){printf("Black wins.\n");con=1;break;}
            else if(board[0][0]==1&&board[1][1]==1&&board[2][2]==1){printf("Black wins.\n");con=1;break;}
            else if(board[2][0]==1&&board[1][1]==1&&board[0][2]==1){printf("Black wins.\n");con=1;break;}

            if(board[0][0]==-1&&board[0][1]==-1&&board[0][2]==-1){printf("White wins.\n");con=1;break;}
            else if(board[1][0]==-1&&board[1][1]==-1&&board[1][2]==-1){printf("White wins.\n");con=1;break;}
            else if(board[0][0]==-1&&board[1][0]==-1&&board[2][0]==-1){printf("White wins.\n");con=1;break;}
            else if(board[2][0]==-1&&board[2][1]==-1&&board[2][2]==-1){printf("White wins.\n");con=1;break;}
            else if(board[0][1]==-1&&board[1][1]==-1&&board[2][1]==-1){printf("White wins.\n");con=1;break;}
            else if(board[0][2]==-1&&board[1][2]==-1&&board[2][2]==-1){printf("White wins.\n");con=1;break;}
            else if(board[0][0]==-1&&board[1][1]==-1&&board[2][2]==-1){printf("White wins.\n");con=1;break;}
            else if(board[2][0]==-1&&board[1][1]==-1&&board[0][2]==-1){printf("White wins.\n");con=1;break;}

            int z=0; 
            for(int a=0;a<3;a++){
                for(int b=0;b<3;b++){
                if(board[a][b]==0){z++;}
                //printf("%d ",board[a][b]);
            }     //       printf("\n");
}
            
            if(z==0){
                con=1;
                printf("There is a draw.\n");
                }

                                    }   
    }
    if(con==0){
        printf("There is a draw.\n");
    }
    return 0;
}