#include<stdio.h>
#include<limits.h>
#define inf INT_MAX
#define ll long long int
#define N 1001
float G[N][N];
float MINCOST(int S,int D,int V[],int n){
	if(S==D)return 0;
	//if(S==n-1)return 0;
	V[S]=1;int i=0;
	float ans=inf;
	for(;i<n;++i){
		if(G[S][i]!=-1 && V[i]==0){
			float C=MINCOST(i,D,V,n);
			float T=ans;
			if((int)C<inf)ans=(T>G[S][i]+C?G[S][i]+C:T);
		}
	}
	V[S]=0;
	return ans;
}
int main()
{
	int n;scanf("%d",&n);int i=0;
	for(;i<n;++i){
		int j=0;
		for(;j<n;++j){
			scanf("%f",&G[i][j]);
		}
	}
	int V[N]={0};
	float ans=MINCOST(0,n-1,V,n);
	if((ll)ans==ans)printf("%lld",(ll)ans);
	else printf("%f",ans);
}
