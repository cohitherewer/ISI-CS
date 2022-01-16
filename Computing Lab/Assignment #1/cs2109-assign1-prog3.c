#include<stdio.h>
#include<string.h>
#define N 1000001
int isNum(char ch){
	return ch>='0' && ch<='9';
}
int main()
{
	char S[N];
	scanf("%[^\n]%*c",S);
	int prev=-1,i=0,SLen=strlen(S);
	for(;i<SLen;++i){
		if(!isNum(S[i])){
			printf("%c",S[i]);int j=0;
			for(;j<prev;++j){
				printf("%c",S[i]);
			}
			prev=-1;
		}else{
			if(prev!=-1){printf("%d",prev);prev=S[i]-'0';}
			else prev=S[i]-'0';
		}
	}
	if(prev!=-1)printf("%d",prev);
}
				
			
