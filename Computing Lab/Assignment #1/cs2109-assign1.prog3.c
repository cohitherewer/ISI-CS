#include<stdio.h>
#include<string.h>
#define N 1000001
#define ll long long
bool isAlphabet(char ch){
	return (ch>='A' && ch<='Z') || (ch>='a' && ch<='z');
}
bool isNumber(char ch){
	return ch>='0' && ch<='9';
}
bool problem(char prevNumber[],int L){
	for(int i=0;i<L;i+=1){
		if(isNumber(prevNumber[i])==false)return true;
	}
	return false;
}
int main(int argc,char **argv)
{
	char *s=argv[1];
	// printf("%s\n",str);
	char prevNumber[N];int i=-1;
	int index=0;
	while(s[index]!='\0'){
		if(isAlphabet(s[index])){
			if(i==-1){printf("%c",s[index]);index+=1;}
			else{
				printf("%c",s[index]);
				int numLength=strlen(prevNumber);
				if(problem(prevNumber,numLength)==true){
					i=-1;
					for(int i=0;i<numLength;i+=1)printf(".");
					printf("%c",s[index]);
				}else{
					ll A=0;
					for(int i=numLength-1;i>=0;i-=1){
						A=A*10+(prevNumber[i]-'0');
					}
					while(A--)printf("%c",s[index]);
				}i=-1;
				index+=1;
			}
		}else if(isNumber(s[index])){
			// int f=0;
			while(s[index]!='\0' && isAlphabet(s[index])==false){
				i+=1;
				prevNumber[i]=s[index];index+=1;
			}i+=1;
			prevNumber[i]='\0';
		}else{
			printf("%c",s[index]);index+=1;
		}
	}
	if(i!=-1){
		int numLength=strlen(prevNumber);
		if(problem(prevNumber,numLength)){
			for(int i=0;i<numLength;i+=1)printf(".");
		}else{
			for(int i=0;i<numLength;i+=1)printf("%c",prevNumber[i]);
		}
	}
}