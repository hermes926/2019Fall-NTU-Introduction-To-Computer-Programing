#include<stdio.h>
#include<string.h>
struct account {
    char name[32];
    unsigned long int balance; 
};



int main(){
    int n;
    scanf("%d", &n);
    struct account data[n];
    for(int i=0;i<n;i++){
        scanf("%s%ld", data[i].name, &data[i].balance);
    }  
    char name1[32], name2[32];
    /*char earns[] = {"earns"};char becomes[] = {"becomes"};
    char gives[] = {"gives"};char spends[] = {"spends"}; */
    while(scanf("%s", name1)!=EOF){
        int firn = -1, secondn = -1;
        for(int i=0;i<n;i++){
            if(strcmp(name1, data[i].name) == 0){
                firn = i;break;}
        }
        if(firn == -1)
            continue;
        char order2[32];
        scanf("%s", order2);int delta=0;
        if(strstr(order2, "earns") != NULL){
            scanf("%d", &delta);
            data[firn].balance += delta;
        }
        else if(strstr(order2, "spends") != NULL ){
            scanf("%d", &delta);
            if(data[firn].balance >= delta)
                data[firn].balance -= delta;
        }
        else if(strstr(order2, "becomes") != NULL){
            scanf("%d", &delta);
            data[firn].balance = delta;
        }
        else if(strstr(order2, "gives") != NULL ){
            scanf("%s", name2);
            for(int i=0;i<n;i++){
                if(strcmp(name2, data[i].name) == 0){
                secondn = i;break;}
            }
            if(secondn == -1)
                continue;
            scanf("%d", &delta);
            if(data[firn].balance >= delta){
                data[firn].balance -= delta;
                data[secondn].balance += delta;
            }
        }
        
    }
    for(int i=0;i<n;i++){
            printf("%s %d\n", data[i].name, data[i].balance);
    }

    return 0;
}