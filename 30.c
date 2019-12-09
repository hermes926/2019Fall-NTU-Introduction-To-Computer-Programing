#include<stdio.h>
int plus(int a,int b,int r,int s,int map[][12]){

	if(map[a][b]==0){
		return 0;
	}
	else if(a==r-1||b==0){
		return 1;
	}
	else
		return plus(a+1,b,r,s,map)+plus(a,b-1,r,s,map);

}

int main(){
	int r,s,f;
	scanf("%d%d",&r,&s);
	int map[12][12];
	for(int c=0;c<r;c++){
		for(int d=0;d<s;d++){
			scanf("%d",&map[c][d]);
		}
	}
    for(int c=r-1;c>=0;c--){
        if(map[c][0]==0){
            for(int d=c;d>=0;d--){
                map[d][0]=0;
            }
            break;
        }
    }
    for(int c=0;c<s;c++){
        if(map[r-1][c]==0){
            for(int d=c;d<s;d++){
                map[r-1][d]=0;
            }
            break;
        }
    }
    /*for(int c=0;c<r;c++){
		for(int d=0;d<s;d++){
			printf("%d ",plus(c,d,r,s,map));
		}
        printf("\n");
	}*/


	f=plus(0,s-1,r,s,map);
	printf("%d\n",f);
	return 0;
} 


