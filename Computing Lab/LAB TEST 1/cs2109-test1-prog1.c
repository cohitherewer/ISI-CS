#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long 
void ARRAY(char *str,ll *arr,ll *index,ll a){
	for(int i=0;i<a;){
		int num=0;int f=0;
		while(str[i]>='0' && str[i]<='9'){
			num=num*10+str[i]-'0';f=1;i+=1;
		}
		if(f==1){arr[*index]=num;*index+=1;}
		if(f==0)i+=1;
	}
}
ll func(ll *arr,ll n){
	ll lM=0,rM=0,low=0,high=n-1,result=0;
	while(low<=high){
		if(arr[low]<arr[high]){
			if(arr[low]>lM) {lM=arr[low];}
			else {result+=(lM-arr[low]);}
			low+=1;
		}else{
			if(arr[high]>rM){rM=arr[high];}
			else{ result+=(rM-arr[high]); }
			high-=1;
		}
	}
	return result;
}
int main()
{
	// ll n=0;
	ll y=pow(10,6)+1;
	ll arr[y]={0};ll index=0;
	char str[100000];
	scanf("%[^\n]%*c",str);
	// printf("%s\n",str);
	// printf("%lld",(ll)strlen(str));
	ARRAY(str,arr,&index,strlen(str));
	printf("%lld\n",func(arr,index));
}