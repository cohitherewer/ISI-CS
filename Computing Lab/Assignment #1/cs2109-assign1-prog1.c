#include<stdio.h>
#include<string.h>
#define N 1000000
void swap(char *c,char *d){
	char T=*d;*d=*c;*c=T;
}
int main()
{
	char S[N],L[N];
	scanf("%s %s",S,L);
	//scanf("%[^\n]%*c",L);
	
	int SLen=strlen(S),LLen=strlen(L),i=0;
	//printf("slen= %d llen=%d",SLen,LLen);
	for(;i<LLen;++i){
		char T[SLen/2+1];int index=0;
		int left=0,right=SLen-1;
		while(left<=right){
			T[index]=(S[left]>S[right]?S[left]:S[right]);
			++index;++left;--right;
		}T[index]='\0';
		SLen=strlen(T);
		if(L[i]=='L'){
			left=0,right=SLen-1;
			while(left<=right){
				swap(&T[left],&T[right]);++left;--right;
			}
		}
		int j=0;
		for(;j<SLen;++j){
			S[j]=T[j];
			printf("%c",T[j]);
		}
		printf(" ");
	}
}
