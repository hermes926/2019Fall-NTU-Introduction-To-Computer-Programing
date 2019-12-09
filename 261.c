#include<stdio.h>
#include<string.h>

int trys1(char s1[], char alp[],int test[],int alpcount){
    int mul=1,fin=0;
    for(int c=0;c<strlen(s1);c++){
        mul*=10;
    }
    for(int c=0;c<strlen(s1);c++){
        mul/=10;
        for(int d=0;d<alpcount;d++){
            if(s1[c] == alp[d]){
                fin+=(test[d]*mul);break;
            }   
        }
        if(s1[c]<=57 && s1[c]>=48){
                fin+=(s1[c]-48)*mul;
        }
    }
    return fin;
}

int trys2(char s2[], char alp[],int test[],int alpcount){
    int mul=1,fin=0;
    for(int c=0;c<strlen(s2);c++){mul*=10;}
    for(int c=0;c<strlen(s2);c++){
        mul/=10;
        for(int d=0;d<alpcount;d++){
            if(s2[c] == alp[d]){
                fin+=(test[d]*mul);break;
            }
            }
        if(s2[c]<=57 && s2[c]>=48){
                fin+=(s2[c]-48)*mul;
    }
    }
    return fin;
}

int tryan(char an[], char alp[],int test[],int alpcount){
    int mul=1,fin=0;
    for(int c=0;c<strlen(an);c++){mul*=10;}
    for(int c=0;c<strlen(an);c++){
        mul/=10;
        for(int d=0;d<alpcount;d++){
            if(an[c] == alp[d]){
                fin+=(test[d]*mul);break;
            }
    }
        if(an[c]<=57 && an[c]>=48){
                fin+=(an[c]-48)*mul;
    }}
    return fin;
}

int main(){
    char st1[10],st2[10],an[20];int alp[26]={0};
    scanf("%s %s %s", st1, st2, an);
    for(int c=0;c<strlen(st1);c++){
        for(int d=65;d<=90;d++){
            if(st1[c]==d){
                alp[d-65]++;
                break;
            }
        }
    }
    for(int c=0;c<strlen(st2);c++){
        for(int d=65;d<=90;d++){
            if(st2[c]==d){
                alp[d-65]++;
                break;
            }
        }
    }
    for(int c=0;c<strlen(an);c++){
        for(int d=65;d<=90;d++){
            if(an[c]==d){
                alp[d-65]++;
                break;
            }
        }
    }
    int alpcount=0;char cha[26]={0};
    for(int c=0;c<26;c++){
        if(alp[c]!=0){
            cha[alpcount]=c+65;alpcount++;
        }
    }
    //printf("%s", cha);
    int test[alpcount];int count=1;int b=1,a=0;
    for(int c=0;c<alpcount;c++){
        test[c]=0;count*=10;
    }
    while(a<count){
        b=1;
        for(int c=0;c<alpcount;c++){
            test[c]=(a/b)%10;b*=10;
        }
        //printf("%d %d %d \n",trys1(st1, cha, test, alpcount), trys2(st2, cha, test, alpcount), tryan(an, cha, test, alpcount));
        if(trys1(st1, cha, test, alpcount) * trys2(st2, cha, test, alpcount) == tryan(an, cha, test, alpcount)){
            int fin1=trys1(st1, cha, test, alpcount),fin2=trys2(st2, cha, test, alpcount),finan=tryan(an, cha, test, alpcount);
            int d=0;
            for(d=strlen(st1)-1;d>=0;d--){
                if(fin1 <= 10){ break;}
                fin1/=10;
            }
            for(int e=0;e<d;e++){
                printf("0");
            }
            printf("%d x ",trys1(st1, cha, test, alpcount));
            d=0;
            for(d=strlen(st2)-1;d>=0;d--){
                if(fin2 <= 10){ break;}
                fin2/=10;
            }
            for(int e=0;e<d;e++){
                printf("0");
            }
            printf("%d = ",trys2(st2, cha, test, alpcount));
            d=0;
            for(d=strlen(an)-1;d>=0;d--){
                if(finan <= 10){ break;}
                finan/=10;
            }
            for(int e=0;e<d;e++){
                printf("0");
            }
            printf("%d\n",tryan(an, cha, test, alpcount));
            
            
            //printf("%d x %d = %d\n",trys1(st1, cha, test, alpcount), trys2(st2, cha, test, alpcount), tryan(an, cha, test, alpcount));
            break;
        }
        a++;
    }
    
    



    return 0;
}