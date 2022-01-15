#include<stdio.h>
#include<string.h>
#include<math.h>
#define ll long long
bool isLogical(char c){
	return c=='>' || c=='<' || c=='=' || c=='!' || c=='~' || c=='&' || c=='|' || c=='+'
	|| c=='-' || c=='*' || c=='/' || c=='%';
}
int main()
{
	ll y=pow(10,5)+1;
	char stack[y];ll j=0;
	char input[y];
	scanf("%[^\n]%*c",input);
	// printf("%s",input);
	// int equalCount=0;
	ll index=0;int f=1;
	for(;index<(ll)strlen(input);index+=1){
		if(input[index]==';')break;
		if(input[index]==' ')continue;
		else if(input[index]=='=')break;
	}
	for(ll i=index+1;i<(ll)strlen(input);i+=1){
		if(input[i]==';')break;
		else if(isLogical(input[i])){
			// if(j==-1)j=0;
			if(i<(ll)strlen(input)-1 && isLogical(input[i+1]))i+=1;
			stack[j++]='$';
		}else if(input[i]=='?'){
			if(j!=-1 && stack[j-1]=='$'){stack[j++]='?';f=1;}
			else {f=0;break;}
		}else if(input[i]==':'){
			if(j!=0 && j!=1 && stack[j-1]=='?' && stack[j-2]=='$'){
				j-=2;
			}else{f=0;break;}
		}
	}
	char ANS[]="VALID";
	if(j!=0 || f==0)printf("IN");
	printf("%s",ANS);
}