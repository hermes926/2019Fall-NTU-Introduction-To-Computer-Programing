#include<stdio.h>
 
int main(){
    int a,b,c,d,e;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    int x=0,c1=-2,c2=-2,c3=-2,n1=0,n2=0,n3=0;int fc=0;
    while(scanf("%d",&x)!=EOF){
        int count=0,con=0;int tx=x;
        while(con==0){
        if(x<=e&&x>=d){
            break;
        }
        count++;
        if((a*tx+b)%c<=e&&(a*tx+b)%c>=d){
            con=1;        }
        else{
            tx=(a*tx+b)%c;
 
        }
        } 
        //printf("%d\n",count);
        c3=c2;n3=n2;
        c2=c1;n2=n1;
        c1=count;n1=x;
        int a1=0,a2=0,a3=0;
 
        if(c1>c2&&c2>c3){a1=c1;a2=c2;a3=c3;        }
        else if(c1>c3&&c3>c2){a1=c1;a2=c3;a3=c2;        }
        else if(c2>c1&&c1>c3){a1=c2;a2=c1;a3=c3;        }
        else if(c2>c3&&c3>c1){a1=c2;a2=c3;a3=c1;        }
        else if(c3>c2&&c2>c1){a1=c3;a2=c2;a3=c1;        }
        else if(c3>c1&&c1>c2){a1=c3;a2=c1;a3=c2;        }
        if(a3==a2-1&&a2==a1-1){
            fc=1;break;
        }
        //printf("%d %d %d\n",c1,c2,c3 );
 
    }
 
 
    if(fc==1){
    printf("%d %d %d\n",n3,n2,n1);}
    else{
        printf("Not found\n");
    }
    return 0;
}