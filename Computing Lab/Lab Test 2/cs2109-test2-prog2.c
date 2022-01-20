#include<stdio.h>
#define N 1001
#define M 1000001
int main()
{
	int X,Y;char A=' ';
	int V[M];int index=-1;
	scanf("%d%d",&X,&Y);int count=0;
	//printf("%d %d",X,Y);
	while(A!=EOF){
		scanf("%c",&A);
		char ch;scanf("%c",&ch);
		count+=1;
		printf("count= %d \n",count);
		if(ch=='+'){
			int S=0;scanf("%d",&S);
			if(index<=X-1){
				V[++index]=S;
			}
			//printf("index =%d",index);
			//int l=0;for(;l<=index;l++)printf("%d ",V[l]);printf("\n");
			if(count==Y){
				//V[index/2]=-1;
				int i=index/2;
				for(;i<index;++i){
					V[i]=V[i+1];
				}index-=1;count=0;
			}int i=0;
			printf("+ %d\n",S);
			for(;i<=index;++i)printf("%d ",V[i]);
			printf("\n");
		}else{
			if(index>=0){--index;}
			if(count==Y){
				int i=index/2;
				for(;i<index-1;++i){
					V[i]=V[i-1];
				}index-=1;count=0;
			}int i=0;
			printf("-");
			for(;i<=index;++i)printf("%d ",V[i]);
			printf("\n");
		}
	}
}
		
