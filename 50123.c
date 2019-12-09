#include<stdio.h>
struct pos{
	int count;
	int x;
	int y;
};


struct pos run(int N,int b[N][N],struct pos in){
	struct pos re;re.count=in.count;re.x=0;re.y=0;
	if(in.x-1>=0 && in.y+1<N && b[in.x-1][in.y+1]==0){
		re.x=in.x-1;re.y=in.y+1;
	}
	else if(in.x-1>=0 && in.y+1<N && b[in.x-1][in.y+1]!=0){
		while (b[in.x+1][in.y]!=0){
			in.x++;if(in.x>=N){in.x=-1;}
		}
		re.x=in.x+1;re.y=in.y;
	}
	else if(in.x-1<0 && in.y+1<N){
		if(b[N-1][in.y+1]==0){
			in.x=N-2;
		}
		else{
			while (b[in.x+1][in.y]!=0){
			in.x++;
		}}
		re.x=in.x+1;re.y=in.y+1;
	}
	else if(in.x-1>=0 && in.y+1>=N){
		if(b[in.x-1][0]==0){
			in.y=0;
		}
		else{while (b[in.x-1][in.y]!=0){
			in.x++;if(in.x>=N){in.x=0;}
		}}
		re.x=in.x-1;re.y=in.y;
	}
	else{
		if(b[N-1][0]==0){
			in.x=N-1;in.y=0;
		}
		
		while(b[in.x][in.y]!=0){
			in.x++;if(in.x>=N){in.x=0;}
		}
		re.x=in.x;re.y=in.y;
	}
	return re;


}

struct pos rerun(int N,int b[N][N],struct pos in){
	struct pos re;re.count=in.count;
	if(in.y-1>=0 && in.x+1<N && b[in.x+1][in.y-1]==0){
		re.x=in.x+1;re.y=in.y-1;
	}
	else if(in.y-1>=0 && in.x+1<N && b[in.x+1][in.y-1]!=0){
		while (b[in.x-1][in.y]!=0){
			in.x-=1;if(in.x<0){in.x=N;}
		}
		re.x=in.x-1;re.y=in.y;
	}
	else if(in.y-1<0 && in.x+1<N){
		if(b[in.x+1][N-1]==0){
			in.x=in.x+2;in.y=N-1;
		}
		else{
			while (b[in.x-1][in.y]!=0){
			in.x-=1;if(in.x<0){in.x=N;}
		}}
		re.x=in.x-1;re.y=in.y;
	}
	else if(in.y-1>=0 && in.x+1>=N){
		if(b[0][in.y-1]==0){
			in.x=1;
		}
		else{while (b[in.x-1][in.y]!=0){
			in.x-=1;if(in.x<0){in.x=N;}
		}}
		re.x=in.x-1;re.y=in.y;
	}
	else{
		if(b[0][N-1]==0){
			in.y=N-1;in.x=0;
		}
		
		while(b[in.x][in.y]!=0){
			in.x-=1;if(in.x<0){in.x=N;}
		}
		re.x=in.x;re.y=in.y;
	}
	return re;


}


int main(){
	int n,k,x,y=0;
	scanf("%d%d%d%d",&n,&k,&x,&y);
	int board[n][n];
	for(int c=0;c<n;c++){
		for(int d=0;d<n;d++){
		board[c][d]=0;}}
	board[x][y]=k;
	struct pos t;
	t.count=1;t.x=x;t.y=y;
	//printf("%d %d %d\n",t.count,t.x,t.y);
	if(k==1){
		for(int c=2;c<=n*n;c++){
			t=run(n,board,t);
			board[t.x][t.y]=c;
			t.count++;
			

		}
	}
	else{
		for(int c=k;c>0;c++){
			t=rerun(n,board,t);
		}
		for(int c=1;c<n*n;c++){
			t=run(n,board,t);
			board[t.x][t.y]=c;
			t.count++;
		}
	}
	for(int c=0;c<n;c++){
		for(int d=0;d<n;d++){
			if(d!=n-1){printf("%d ",board[c][d]);
		}
			else{
				printf("%d",board[c][d]);
			}}
		printf("\n");
	}
	return 0;
}


