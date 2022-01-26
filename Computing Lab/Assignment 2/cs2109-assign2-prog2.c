#include<stdio.h>
#define N 1001
char M[N][N];
int R,C;
int isVowel(char ch){
	if(ch>='A' && ch<='Z')ch=ch-'A'+'a';
	return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}
int max(int a,int b){
	return a>b?a:b;
}
void DFS(int X,int Y,int *cnt){
	if(X<0 || Y<0 || X>=R || Y>=C || isVowel(M[X][Y])==0)return;
	*cnt+=1;M[X][Y]='.';
	DFS(X-1,Y-1,cnt);
	DFS(X-1,Y-1,cnt);
	DFS(X-1,Y+1,cnt);
	DFS(X,Y-1,cnt);
	DFS(X,Y+1,cnt);
	DFS(X+1,Y-1,cnt);
	DFS(X+1,Y,cnt);
	DFS(X+1,Y+1,cnt);
}
int main()
{
	scanf("%d%d",&R,&C);int i=0;char T;scanf("%c",&T);
	//printf("%d %d",R,C);
	for(;i<R;++i){
		int j=0;
		for(;j<C;){
			T=getchar();
			if(T!=' ')M[i][j++]=T;
		}
		T=getchar();
	}i=0;
	//for(;i<R;++i){
		//int j=0;
		//for(;j<C;++j){
			//printf("%c",M[i][j]);
		//}
		//printf("\n");
	//}
	int ans=0,cnt=0;
	for(;i<R;++i){
		int j=0;
		for(;j<C;++j){
			if(isVowel(M[i][j]))DFS(i,j,&cnt);
			ans=max(cnt,ans);cnt=0;
		}
	}
	printf("%d",ans);
}
