#include<stdio.h>
#include<string.h>



typedef struct data{
    char lastname[81];
    char firstname[81];
    char ID[81];
    int salary;
    int age;
}Data;

int oper1(char op[]){
    if(op[0] == '>')
        return 1;
    else if(op[0] == '<')
        return -1;
    else if(op[0] == '!')
        return 2;
    else
        return 0;
}

void print(char order[][10], int d, Data in){
    for(int i=0;i<d;i++){
        if(strstr(order[i], "age") != NULL)
            printf("%d", in.age);
        else if(strstr(order[i], "firstname") != NULL)
            printf("%s", in.firstname);
        else if(strstr(order[i], "lastname") != NULL)
            printf("%s", in.lastname);
        else if(strstr(order[i], "ID") != NULL)
            printf("%s", in.ID);
        else if(strstr(order[i], "salary") != NULL)
            printf("%d", in.salary);
        (i == d-1) ? printf("\n") : printf(" "); 
    }
    
}

int main(){
    int n=0;
    scanf("%d",&n);Data list[50];
    for(int c=0;c<n;c++)
        scanf("%s%s%s%d%d",list[c].lastname, list[c].firstname, list[c].ID, &list[c].salary, &list[c].age);
    char useless[10],order[9][10];int d=0;
    //char where[6]= {'w','h','e','r','e', '\0'};
    int t=0;scanf("%d", &t);
    for(int i=0;i<t;i++){
        scanf("%s",useless);
        d = 0;
        while(1){
            scanf("%s", order[d]);
            if(strstr(order[d], "where") != NULL)
                break;
            d++;
        }
        char compar[10]= {0};
        scanf("%s", compar);
        //printf("%s---", compar);
        char compare[10]={0};
        strcpy(compare, compar);
        //printf("%s\n\n", compare);
        char oper[2];scanf("%s", oper);
        if(strstr(compar, "salary") != NULL || strstr(compar, "age") != NULL){
            //printf("%s-_-\n", compar);
            int com;scanf("%d", &com);
            if(strstr(compar, "salary") != NULL){
                for(int j=0;j<n;j++){
                    switch(oper1(oper)){
                        case 1:
                            if(list[j].salary > com){
                                print(order, d, list[j]);
                            }break;
                        case -1:
                            if(list[j].salary < com){
                                print(order, d, list[j]);
                            }break;
                        case 0:
                            if(list[j].salary == com){
                               print(order, d, list[j]);
                            }break;
                    }
                }
            }
            else{
                for(int j=0;j<n;j++){
                    switch(oper1(oper)){
                        case 1:
                            if(list[j].age > com){
                                print(order, d, list[j]);
                            }break;
                        case -1:
                            if(list[j].age < com){
                                print(order, d, list[j]);
                            }break;
                        case 0:
                            if(list[j].age == com){
                               print(order, d, list[j]);
                            }break;
                    }
                }
            }

        }
        else{
            //printf("%s--%s--\n", compare, compar);
            char itemname[10];scanf("%s", itemname);
            if(strstr(compar, "firstname") != NULL){
                //printf("f i r s t\n");
                for(int j=0;j<n;j++){
                    switch(oper1(oper)){
                        case 2:
                            if(strcmp(list[j].firstname, itemname) != 0){
                               print(order, d, list[j]);
                            }break;
                        case 0:
                            if(strcmp(list[j].firstname, itemname) == 0){
                               print(order, d, list[j]);
                            }break;
                    }
                }
            }
            else if(strstr(compar, "lastname") != NULL){
                //printf("l a s t\n");
                for(int j=0;j<n;j++){
                    switch(oper1(oper)){
                        case 2:
                            if(strcmp(list[j].lastname, itemname) != 0){
                               print(order, d, list[j]);
                            }break;
                        case 0:
                            if(strcmp(list[j].lastname, itemname) == 0){
                               print(order, d, list[j]);
                            }break;
                    }
                }
            }
            else{
                //printf("I D\n");
                for(int j=0;j<n;j++){
                    switch(oper1(oper)){
                        case 2:
                            if(strcmp(list[j].ID, itemname) != 0){
                               print(order, d, list[j]);
                            }break;
                        case 0:
                            if(strcmp(list[j].ID, itemname) == 0){
                               print(order, d, list[j]);
                            }break;
                    }
                }
            }
        }
    }
    return 0;
}