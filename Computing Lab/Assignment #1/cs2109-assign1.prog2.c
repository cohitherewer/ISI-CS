#include<stdio.h>
#define N 1001
define ll long long
void dfs(ll M[N][N],int top,int bottom,int left,int right,char dir,int X,int Y,int *count){
	if(*count==0)return;
	printf("%lld ",M[X][Y]);*count-=1;
	if(dir=='U'){
		// printf("Top\n");
		if(X<=top)dfs(M,top,bottom,left,right-1,'L',X,Y-1,count);
		else dfs(M,top,bottom,left,right,'U',X-1,Y,count);
	}else if(dir=='L'){
		// printf("Left\n");
		if(Y<=left)dfs(M,top+1,bottom,left,right,'D',X+1,Y,count);
		else dfs(M,top,bottom,left,right,'L',X,Y-1,count);
	}else if(dir=='D'){
		// printf("Down\n");
		if(X>=bottom)dfs(M,top,bottom,left+1,right,'R',X,Y+1,count);
		else dfs(M,top,bottom,left,right,'D',X+1,Y,count);
	}else{
		// printf("Right\n");
		if(Y>=right)dfs(M,top,bottom-1,left,right,'U',X-1,Y,count);
		else dfs(M,top,bottom,left,right,'R',X,Y+1,count);
	}
}
int main()
{
	int R,C;scanf("%d%d",&R,&C);
	ll M[N][N];
	for(int i=0;i<R;i+=1){
		for(int j=0;j<C;j+=1){
			scanf("%lld",&M[i][j]);
		}
	}
	int count=R*C;
	dfs(M,0,R-1,0,C-1,'U',R-1,C-1,&count);
}
