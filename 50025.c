#include<stdio.h>
#include<stdbool.h>
int a = 0;

bool findrelation(bool inre[][100], int m, int n, int num, int count, int chosen[100]){
    if(a == 0){
        //printf("%d %d\n", count, num);
        //if it is end
        if(num == n){
            for(int i=0;i<n;i++){
                    printf("%d ", chosen[i]);
            }
            printf("\n");
            a = 1;
            return true;
        }
            
        else if(count == m)
            return false;
        // reset the array
        bool re = true;
        for(int i=num;i<n;i++)
            chosen[i] = 0;
        //if it's legal to add the current person into the whole array
        for(int i=0;i<num;i++){
            if(inre[chosen[i]][count]){
                re = false;break;
            }
        }
        // if not
        bool anw = findrelation(inre, m, n, num, count+1, chosen);
        // if yes
        if(re){
            chosen[num] = count;num++;
            //printf("----- %d\n", num);
            anw += findrelation(inre, m, n, num, count+1, chosen);
        }
        
        return anw;
    }
    else{
        return true;
    }
}

int main(){
    int m, n;
    while(scanf("%d%d", &m, &n)!=EOF){
        a = 0;
        bool relation[100][100];
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                scanf("%d", &relation[i][j]);
            }
        }
        int chosen[100] = {0};
        bool final = findrelation(relation, m, n, 0, 0, chosen);
        if(!final)
            printf("no solution\n");
    }

    return 0;
}