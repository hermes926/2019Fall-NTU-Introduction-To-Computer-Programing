#include<stdio.h>

int main(){
    int n,m,x,y,energy,sn;
    scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&energy,&sn);
    int s[sn][3];int map[n][m];
    
    for(int c=0;c<n;c++){
        for(int d=0;d<m;d++){
            map[c][d]=0;
        }
    }
    map[x][y]=energy;
    for(int c=0;c<sn;c++){
        int sx,sy,se;
        scanf("%d%d%d",&sx,&sy,&se);
        map[sx][sy]=se;
    }
    
    int ins,te,dis;
    while(scanf("%d",&ins)!=EOF){
    te=0;dis=0;
    switch(ins){
    case 0:
    for(int c=0;c<n;c++){
        for(int d=0;d<m;d++){
            if(d!=m-1)
               { printf("%d ",map[c][d]);}
            else{printf("%d\n",map[c][d]);}
        }
    }
    break;


    case 1:
    
    for(int c=1;c<m-y;c++){
        if(map[x][y+c]>0)
        {te+=map[x][y+c];dis++;}
        else{break;}
    }
    
    if(energy>=te&&(dis!=m-y-1||map[x][m-1]==0)){
        energy-=te;map[x][y]-=te;
        for(int d=dis+1;d>0;d=d-1){
            map[x][y+d]=map[x][y+d-1];
        }
        map[x][y]=0;
        y++;

    }
    break;
    case 2:
    
    for(int c=1;c<n-x;c++){
        if(map[x+c][y]>0)
        {te+=map[x+c][y];dis++;}
        else{break;}
    }
    
    if(energy>=te&&(dis!=n-x-1||map[n-1][y]==0)){
        energy-=te;map[x][y]-=te;
        for(int d=dis+1;d>0;d=d-1){
            map[x+d][y]=map[x+d-1][y];
        }
        map[x][y]=0;
        x++;

    }
    break;

    case 3:
    for(int c=y-1;c>=0;c=c-1){
        if(map[x][c]>0)
        {te+=map[x][c];dis++;}
        else{break;}
    }
    
    if(energy>=te&&(dis!=y||map[x][0]==0)){
        energy-=te;map[x][y]-=te;
        for(int d=dis+1;d>0;d=d-1){
            map[x][y-d]=map[x][y-d+1];
        }
        map[x][y]=0;
        y-=1;

    }
    break;

    case 4:
    for(int c=x-1;c>=0;c=c-1){
        if(map[c][y]>0)
        {te+=map[c][y];dis++;}
        else{break;}
    }
    
    if(energy>=te&&(dis!=x||map[0][y]==0)){
        energy-=te;map[x][y]-=te;
        for(int d=dis+1;d>0;d=d-1){
            map[x-d][y]=map[x-d+1][y];
        }
        map[x][y]=0;
        x-=1;

    }
    break;


    
    
    
    }}
    //printf("")
    return 0;
}