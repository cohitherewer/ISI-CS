#include<stdio.h>
#define N 1001
#define ll long long

ll M[N][N];
int ROW,COL;
int T,B,L,R;

void DFS(char dir,int X,int Y,int *count){
	if(*count==0)return;
	printf("%lld ",M[X][Y]);*count-=1;
	if(dir=='U'){
		// printf("Top\n");
		if(X<=T){--R;DFS('L',X,Y-1,count);}
		else DFS('U',X-1,Y,count);
	}else if(dir=='L'){
		// printf("Left\n");
		if(Y<=L){++T;DFS('D',X+1,Y,count);}
		else DFS('L',X,Y-1,count);
	}else if(dir=='D'){
		// printf("Down\n");
		if(X>=B){++L;DFS('R',X,Y+1,count);}
		else DFS('D',X+1,Y,count);
	}else{
		// printf("Right\n");
		if(Y>=R){--B;DFS('U',X-1,Y,count);}
		else DFS('R',X,Y+1,count);
	}
}
int main()
{
	scanf("%d%d",&ROW,&COL);
	for(int i=0;i<ROW;i+=1){
		for(int j=0;j<COL;j+=1){
			scanf("%lld",&M[i][j]);
		}
	}
	int count=ROW*COL;
	T=0,B=ROW-1,L=0,R=COL-1;
	DFS('U',ROW-1,COL-1,&count);
}
