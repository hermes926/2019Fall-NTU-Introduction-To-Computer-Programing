#include<stdio.h>
int main(){
    int r, h, g, da, exda, coola, db, exdb, coolb, dc, exdc, coolc, dn;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d", &r, &h, &g, &da, &exda, &coola, &db, &exdb, &coolb, &dc, &exdc, &coolc, &dn);
    int counta=0, countb=0, countc=0; int tda=0,tdb=0,tdc=0;int timea=0,timeb=0,timec=0;
    int maxh=h;
    for(int c=0;c<r;c++){
        if(counta==0){
            if(coola-c>=0){tda=da;}
            else{tda=da+exda*(c-coola);}
        }
        else{
            if(c-timea<coola){tda=0;}
            else{tda=(c-timea-coola)*exda+da;}
        }
        if(countb==0){
            if(coolb-c>=0){tdb=db;}
            else{tdb=db+exdb*(c-coolb);}
        }
        else{
            if(c-timeb<coolb){tdb=0;}
            else{tdb=(c-timeb-coolb)*exdb+db;}
        }
        if(countc==0){
            if(coolc-c>=0){tdc=dc;}
            else{tdc=dc+exdc*(c-coolc);}
        }
        else{
            if(c-timec<coolc){tdc=0;}
            else{tdc=(c-timec-coolc)*exdc+dc;}
        }
        if(tda>=tdb&&tda>=tdc&&tda>=dn){h-=tda;timea=c;counta++;//printf("a ");
        }
        else if(tdb>tda&&tdb>=tdc&&tdb>=dn){h-=tdb;timeb=c;countb++;//printf("b ");
        }
        else if(tdc>tda&&tdc>=tdb&&tdc>=dn){h-=tdc;timec=c;countc++;//printf("c ");
        }
        else{h-=dn;//printf("n ");
        }
        printf("%d ",h);
        if(h<=0){break;}
        else if(h+g>maxh){h=maxh;}
        else{h+=g;}   
    }
    return 0;
}