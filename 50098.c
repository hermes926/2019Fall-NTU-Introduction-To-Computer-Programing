#include<stdio.h>
#include<stdbool.h>

void find(unsigned long long int group[], unsigned long long int final,int totalgroup, int requiredgroup, int now, int *con, bool used[]){
    if(requiredgroup == 0)
        *con = true;
        
    else if(!(*con)){
        if(group[now] & final == 0){
            used[now] = 1;
            find(group, final+group[now] , totalgroup, requiredgroup-1, now+1, con, used);
        }
        if(!(*con)){
            used[now] = 0;
            find(group, final , totalgroup, requiredgroup, now+1, con, used);
        }
    }
}

int main(){
    int n, m;int found = 0;
    int *foundptr = &found;
    unsigned long long int group[10];
    bool used[n];
    //for(int i=0;i<n;i++)
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;i++){
        used[i] = 0;
        group[i] = 0;int people = 0, ID =0;
        scanf("%d", &people);
        unsigned long long int modifier = 1;
        for(int j=0;j<people;j++){
            scanf("%d", &ID);
            modifier = modifier << ID;
            group[i] |= modifier;
            modifier = 1;
        }
    }
    for(int i=0;i<n;i++){
        printf("%lld\n", group[i]);
    }
    find(group, 0, n, m, 0, foundptr, used);
    for(int i=0;i<n;i++){
        if(used[i])
            printf("%d ", i);
        
    }


    return 0;
}