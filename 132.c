#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

/*bool ok(int color[],int n,bool arr[n][n]){
    bool fin=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(color[i]==color[j] && (!arr[i][j])){
                fin=false;//printf("%d %d\n",i,j);
                break;
            }
        }
        if(!fin){break;}
    }
    return fin;
}*/

int gen(int color[], int n, int c, bool arr[n][n], int nown, bool* condition){
    if(!(*condition)){    
        int final = 0;
        if(nown == n){
            for(int i=0;i<n;i++){
                printf("%d\n", color[i]+1);
            }
            *condition = true;
            return 1;
        }
        else{
            for(int i=0;i<c;i++){
                color[nown] = i;bool found = true;
                for(int j=0;j<nown;j++){
                    if(color[nown]==color[j] && (!arr[nown][j])){
                        found = false; break;
                    }
                }
                if(found){
                    final += gen(color, n, c, arr, nown+1, condition);
                }
            }
            return final;
        }
    }
    else{
        return 0;
    }
}
 
int main(){
    int n,c,p;
    scanf("%d%d%d",&n,&c,&p);
    bool pair[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pair[i][j]=true;
        }
    }
 
    int x,y;
    for(int i=0;i<p;i++){
        scanf("%d%d", &x,&y);
        pair[x][y]=false;pair[y][x]=false;
    }
 
 
    //printf("------\n");
    int color[n];
    bool condition = false;bool* ptr = &condition;
    int print = gen(color, n, c, pair, 0, ptr);
    if(print == 0)
        printf("no solution.\n"); 
 
    return 0;
}