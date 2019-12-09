#include<stdio.h>

int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int l;int date=0;
    l=0;
    if(a%4==0){l=1;
        if(a%100==0){l=0;
            if(a%400==0){
                l=1;}}}
    switch(b){
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:date=31;break;
        case 4:case 6:case 9:case 11:date=30;break;
        case 2:
            
            if(l==0){date=28;}
            else if(l==1){date=29;}
            //printf("%d\n",l);
            break;
            default: date=-1;
    }
    
    if(date>0&&(c>=0&&c<8)){
    printf(" Su Mo Tu We Th Fr Sa\n=====================\n");
    for(int d=0;d<c;d++){printf("   ");}
    for(int d=1;d<=date;d++){
        if(d<10){printf("%3d",d);}
        else{printf("%3d",d);}
        if(d%7==(7-c)){printf("\n");}
        if(c==0&&d%7==0){printf("\n");}
    }
    if((date-(7-c))%7==0){printf("=====================");}
    else{printf("\n=====================");}
    }
    else{
        printf("invalid\n");
    }
    return 0;
}