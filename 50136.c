#include<stdio.h>
#include<string.h>

void wow(char prev, long long int* nptr, int l, int k, char fi[], int count){
    if(count == l-1 && *nptr > 0){
        fi[count] = prev;
        for(int i=0;i<l;i++)
            printf("%c", fi[i]);
        printf("\n");
        *nptr = *nptr - 1;
        //printf(" %d\n", *nptr);
    }
    else if((*nptr) > 0 && count < l-1){    
        int com = 0;
        for(int i=0;i<k;i++){
            //printf("%d\n",(prev-96+i) );
            if((prev-96+i) >= 26){
                com = i;break;
            }
        }
       //printf("%d\n", com);
        for(int i=com;i<k;i++){
            fi[count] = prev;
            wow(97+((prev-96+i)%26), nptr, l, k, fi, count+1);
            if(*nptr <= 0)
                break;
        }
        for(int i=0;i<com;i++){
            fi[count] = prev;
            wow(97+((prev-96+i)%26), nptr, l, k, fi, count+1);
            if(*nptr <= 0)
                break;
        }

    }
}

int main(){
    char f;int k, l;long long int n;
    scanf("%c%d%d%lld", &f, &k, &l, &n);
    long long int* nptr = &n;
    //printf("%d\n", *nptr); 
    char fi[l];
    for(int i=0;i<l;i++)
        fi[i] = 0;
    wow(f, nptr, l, k, fi, 0);


    return 0;
}