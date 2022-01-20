#include<stdio.h>
#include<string.h>
#define N 100000
int isSame(char X[],char Y[]){
	if(strlen(X)!=strlen(Y))return 0;
	int i=0;
	for(;i<strlen(X);++i){
		if(X[i]!=Y[i])return 0;
	}return 1;
}
int main()
{
	char I[N*20];scanf("%[^\n]%*c", I);
	
	char V[N][20];int i=0,index=0,j=0;
	while(I[i]!='\0'){
		if(I[i]!=' '){
			V[index][j++]=I[i];
		}else{
			V[index][j]='\0';
			++index;j=0;
		}++i;
	}index++;
	//int FREQ=INT_MAX;
	//for(i=0;i<index;i++)printf("%s ",V[i]);
	for(i=0;i<index;++i){
		int C=0;
		for(j=0;j<index;j++){
			C+=isSame(V[i],V[j]);
		}
		if(C>index/2){
			printf("%s",V[i]);return 0;
		}
		//printf("%s",(C>index/2?V[i]:""));
	}
	printf("NIL");
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
