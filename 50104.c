#include<stdio.h>
#include<string.h>
#include<stdbool.h>

typedef struct{
    char name[40];
    char leader[40];
    int membercount;
    char member[1000][40];
}club;

club create(char leader[40], char name[40]){
    club newclub;
    strcpy(newclub.leader, leader);
    strcpy(newclub.name, name);
    //memcpy(newclub.member[0], leader, strlen(leader));
    newclub.membercount = 1;
    //printf("%s %s\n", newclub.leader, newclub.name);
    return newclub;
}

int main(){
    int n,m;
    scanf("%d", &n);
    club all[5000];
    int state = 0, clubcount = 0;
    for(int i=0;i<n;i++){
        scanf("%d", &state);
        char clubname[40], studentname[40];
        scanf("%s%s", studentname, clubname);
        //printf("%s %s\n", studentname, clubname);
        int j=0;
        switch(state){
            case 0:
                all[clubcount] = create(studentname, clubname);
                //printf("%s %s\n", studentname, clubname);
                clubcount++;
                break;
            case 1:
                for(j=0;j<clubcount;j++){
                    if(strcmp(all[j].name, clubname) == 0)
                        break;
                }
                memcpy(all[j].member[all[j].membercount], studentname, strlen(studentname));
                all[j].membercount++;
                break;
        }
    }
    scanf("%d", &m);
    for(int i=0;i<m;i++){
        int state;
        scanf("%d", &state);
        //printf(" %d\n", state);
        char clubname[40], studentname[40];
        switch(state){
            case 0:
                scanf("%s", clubname);
                bool found = false;
                for(int j=0;j<clubcount;j++){
                    if(strcmp(all[j].name, clubname) == 0){
                        printf("%s\n", all[j].leader);
                        found = true;break;
                    }
                }
                if(!found)
                    printf("None\n");
                break;
            case 1:
                scanf("%s%s", studentname, clubname);
                //printf("%s %s\n", studentname, clubname);
                bool clubfound = false, studentfound = false;
                for(int j=0;j<clubcount;j++){
                    if(strcmp(all[j].name, clubname) == 0){
                        clubfound = true;
                        //printf("555\n");
                        //printf("%s %s\n", all[j].leader, studentname);
                        if(strcmp(all[j].leader, studentname) == 0){
                            printf("1\n");
                            studentfound = true;break; 
                        }
                        for(int k=0;k<all[j].membercount;k++){
                            if(strcmp(all[j].member[k], studentname) == 0){
                                printf("1\n");
                                studentfound = true;break; 
                            }  
                        }
                        if(!studentfound)
                            printf("0\n");
                        break;
                    }
                }
                if(!clubfound)
                    printf("-1\n");
                break;
            default: 
                break;
        } 
    }
    return 0;
}