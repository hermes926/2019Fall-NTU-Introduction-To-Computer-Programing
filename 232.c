#include<stdio.h>

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int l=0;int month2=28;
    if(a%4==0){l=1;month2=29;
        if(a%100==0){l=0;month2=28;
            if(a%400==0){
                l=1;month2=29;}}}
    int num;scanf("%d",&num);
    for(int c=0;c<num;c++){
        int month=0,day,con=0;
        scanf("%d%d",&month,&day);
        switch(month){
                case 1:
                    con=(day+b-1)%7;if(day>31||day<=0){con=-2;}break;
                case 3:
                    con=(31+month2+b+day-1)%7;if(day>31||day<=0){con=-2;}break;
                case 5:
                    con=(31+30+31+month2+b+day-1)%7;if(day>31||day<=0){con=-2;}break;
                case 7:
                    con=(31+month2+31+30+31+30+b+day-1)%7;if(day>31||day<=0){con=-2;}break;
                case 8:
                    con=(31+month2+31+30+31+30+31+b+day-1)%7;if(day>31||day<=0){con=-2;}break;
                case 10:
                    con=(31+month2+31+30+31+30+31+31+30+b+day-1)%7;if(day>31||day<=0){con=-2;}break;
                case 12:
                    con=(31+month2+31+30+31+30+31+31+30+31+30+b+day-1)%7;if(day>31||day<=0){con=-2;}break;
                case 4:
                    con=(31+month2+31+b+day-1)%7;if(day>30||day<=0){con=-2;}break;
                case 6:
                    con=(31+month2+31+30+31+b+day-1)%7;if(day>30||day<=0){con=-2;}break;
                case 9:
                    con=(31+month2+31+30+31+30+31+31+b+day-1)%7;if(day>30||day<=0){con=-2;}break;
                case 11:
                    con=(31+month2+31+30+31+30+31+31+30+31+b+day-1)%7;if(day>30||day<=0){con=-2;}break;
                case 2:
                    con=(31+b+day-1)%7;
                if(l==1&&(day>29||day<=0)){con=-2;}
                else if(l==0&&(day>28||day<=0)){con=-2;}
                break;
                default:con=-1;
            }
        
        printf("%d\n",con);

        }
        
    return 0;
}