#include<stdio.h>

int main(){
    int row,col;
    scanf("%d%d",&row,&col);
    int arr[row][col];
    for(int c=0;c<row;c++){
        for(int d=0;d<col;d++){
            scanf("%d",&arr[c][d]);
        }
    }
    int final=0;
    for(int c=0;c<row-2;c++){
        for(int d=0;d<col-3;d++){
            int number[7]={0,1,2,3,4,5,6};
            if(arr[c+1][d]+arr[c+1][d+2]==7 && arr[c+1][d+1]+arr[c+1][d+3]==7 && arr[c+1][d]<7 && arr[c+1][d]>0 && arr[c+1][d+1]<7 && arr[c+1][d+1]>0 && arr[c+1][d]!=arr[c+1][d+1] && arr[c+1][d]!=arr[c+1][d+3]){
                for(int e=0;e<4;e++){
                    number[arr[c+1][d+e]]=0;
                }
                for(int e=0;e<4;e++){
                    for(int f=0;f<4;f++){
                        if(number[arr[c][d+e]]!=0 && number[arr[c+2][d+f]]!=0 && arr[c][d+e]!=arr[c+2][d+f]){
                            final++;
                        }
                    }
                }
                
            }
        }
    }
    printf("%d\n",final);

    
    
    return 0;
}