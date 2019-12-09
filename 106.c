#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char a[1000];
    while(scanf( "%s", a)!=EOF){    
        if(strlen(a)==2 && a[0]== '-' && a[1]=='1'){
            break;
        }
        if((a[strlen(a)-1]-48) % 2 ==0){
            printf("yes ");
        }
        else{printf("no ");}

        int sum=0;int oddsum=0;int evensum=0;
        for(int c=0;c<strlen(a);c++){
            sum+=(a[c]-48);
            if(c%2==0){
                oddsum+=(a[c]-48);
            }
            else{
                evensum+=(a[c]-48);
            }
        }
        //printf("%d %d %d",sum,oddsum,evensum);
        if(sum%3==0){
            printf("yes ");
        }
        else{
            printf("no ");
        }
        if((a[strlen(a)-1]-48)==0 || (a[strlen(a)-1]-48)==5){
            printf("yes ");
        }
        else{
            printf("no ");
        }
        if((oddsum-evensum) % 11 ==0 || oddsum == evensum){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
    return 0;
}