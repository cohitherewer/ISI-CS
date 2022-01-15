#include<stdio.h>
#include<math.h>
#include<string.h>
#define ll long long
void reverse(char *temp,ll left,ll right){
	while(left<=right){
		char c=temp[left];temp[left]=temp[right];temp[right]=c;
		left+=1;right-=1;
	}
}
int main()
{
	ll y=pow(10,6);
	char str[y+1];
	char seq[y+1];

	// take input
	scanf("%s %s",&str,&seq);
	ll strLen=strlen(str),seqLen=strlen(seq);

	for(ll i=0;i<seqLen;i+=1){
		if(strLen==1){
			printf("%s\n", str);
			return 0;
		}
		char temp[strLen/2+1];
		ll index=0,left=0,right=strLen-1;
		while(left<=right){
			if(str[left]>str[right])temp[index++]=str[left];
			else temp[index++]=str[right];
			left+=1;right-=1;
		}
		// temp[index]='\0';printf("temp = %s\n",temp);
		if(seq[i]=='L')reverse(temp,0,index-1);

		for(ll j=0;j<index;j+=1)str[j]=temp[j];

		str[index]='\0';
		strLen=strlen(str);
	}

	printf("%s\n",str);
}