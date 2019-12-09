#include<stdio.h>
#include<string.h>
#include<stdbool.h>

struct employee {
  int id;
  char first_name[32];
  char last_name[32];
  int boss_id;
};

int main(){
    int n;scanf("%d",&n);
    struct employee em[33];
    for(int c=0;c<n;c++){
        scanf("%d %s %s %d",&em[c].id,em[c].first_name,em[c].last_name,&em[c].boss_id);
        //printf("%d %s %s %d\n",em[c].id,em[c].first_name,em[c].last_name,em[c].boss_id);
    }
    int t;scanf("%d",&t);char first1[40],last1[40],first2[40],last2[40];
    for(int c=0;c<t;c++){
        scanf("%s %s %s %s",first1, last1, first2, last2);
        int fir=0,sec=0;
        for(int d=0;d<n;d++){
            if(strcmp(em[d].first_name, first1)==0 && strcmp(em[d].last_name, last1)==0){
                fir=d;
            }
            else if(strcmp(em[d].first_name, first2)==0 && strcmp(em[d].last_name, last2)==0){
                sec=d;
            }
        }
        
        //printf("%d %d\n", fir, sec);
        bool con=true;int final=-1;int tfir=fir;
        while(con){
            if(em[tfir].boss_id == em[sec].id){
                final=0;con=false;
            }
            else{
                if(em[tfir].id == em[tfir].boss_id){
                    break;
                }
                for(int d=0;d<n;d++){
                    if(em[d].id == em[tfir].boss_id){
                        tfir=d;break;
                    }
                }
            }
        }
        //con = true;
        int tsec=sec;
        while(con){
            if(em[tsec].boss_id == em[fir].id){
                final=1;con=false;
            }
            else{
                if(em[tsec].id == em[tsec].boss_id){
                    break;
                }
                for(int d=0;d<n;d++){
                    if(em[d].id == em[tsec].boss_id){
                        tsec=d;break;
                    }
                }
            }
        }
        tsec = sec; tfir = fir;
        while(em[tfir].id != em[tfir].boss_id && con){
            tsec = sec;
            while(em[tsec].id != em[tsec].boss_id){
                if(em[tsec].boss_id == em[tfir].boss_id){
                    final=2;con = false;break;
                }
                for(int d=0;d<n;d++){
                    if(em[d].id == em[tsec].boss_id){
                        tsec=d;break;
                    }
                }
            }
            for(int d=0;d<n;d++){
                    if(em[d].id == em[tfir].boss_id){
                        tfir=d;break;
                    }
            }
                
        }
        //printf("%d ",final);
        switch(final){
            case 0:
                printf("subordinate\n");break;
            case 1:
                printf("supervisor\n");break;
            case 2:
                printf("colleague\n");break;
            default:
                printf("unrelated\n");break;
        }

    }
    
    
    
    
    return 0;
}