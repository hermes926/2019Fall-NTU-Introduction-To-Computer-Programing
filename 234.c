#include<stdio.h>

int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int d=0,e=0,f=0;int count=0;
    if(c>0){
    for(int x=-c;x<=c;x++){
        if(count==0&&(x*x*x+a*x*x+b*x+c==0)){f=-x;count++;
            if(x*x+a*x+x*x+b+a*x+x*x==0){e=-x;count++;
                if(x*x*x==-c){d=-x;break;}}}
       else if(count==1&&(x*x*x+a*x*x+b*x+c==0)){e=-x;count++;
            if(x*x+a*x+x*x+b+a*x+x*x==0){d=-x;break;}}
        else if(count==2&&(x*x*x+a*x*x+b*x+c==0)){d=-x;break;}
    }}
    else if(c<0)
    {
       for(int x=c;x<=-c;x++){
        if(count==0&&(x*x*x+a*x*x+b*x+c==0)){f=-x;count++;
            if(x*x+a*x+x*x+b+a*x+x*x==0){e=-x;count++;
                if(x*x*x==-c){d=-x;break;}}}
        else if(count==1&&(x*x*x+a*x*x+b*x+c==0)){e=-x;count++;
            if(x*x+a*x+x*x+b+a*x+x*x==0){d=-x;break;}}
        else if(count==2&&(x*x*x+a*x*x+b*x+c==0)){d=-x;break;}
    }
    }
    else{
        f=0;
        if(b==0){
            e==0;d=a;
        }
        else{
            if(b>0)
            {for(int x=-b;x<=b;x++){
                if(count==0&&(x*x+a*x+b==0)){e=-x;count++;if(x*x==b){d=-x;break;}}
                else if(count==1&&(x*x+a*x+b==0)){d=-x;break;}

            }}
            else{
            for(int x=b;x<=-b;x++){
                if(count==0&&(x*x+a*x+b==0)){e=-x;count++;if(x*x==b){d=-x;break;}}
                else if(count==1&&(x*x+a*x+b==0)){d=-x;break;}

            } 
            }

        }
    }
    
    if(e<d&&d<f){
        int tem=e;e=d;d=tem;
    }
    else if(e>=f&&f>=d){
        int tem=f;f=e;e=tem;
    }
    else if(f<=d&&f>=e){
        int tem=f;f=d;d=tem;
         tem=e;e=d;d=tem;
    }
    else if(d>=f&&e>=d){
        int tem=f;f=d;d=tem;
         tem=e;e=f;f=tem;
    }
    else if(d>=e&&e>=f){
        int tem=f;f=d;d=tem;
    }
    

    printf("%d %d %d\n",d,e,f);

    return 0;
    
}