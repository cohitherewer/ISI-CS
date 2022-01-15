#include<stdio.h>
#define ll long long
ll totalSum(ll arr[],ll n){
	ll sum=0,i=0;
	for(i=0;i<n;i++){
		sum+=arr[i];
	}
	return sum;
}
ll subSum(ll arr[],ll n){
	ll sum=0;
	for(int i=0;i<n-1;i+=1){
		sum+=(arr[i]-arr[i+1]);
	}
	return sum;
}
bool isDecrease(ll arr[], ll n){
	for(int i=1;i<n;i++){
		if(arr[i]>arr[i-1]){
			return false;
		}
	}
	return true;
}
ll min(ll n,ll m){
	if(n>m)return m;
	else return n;
}
ll gcd(ll n,ll m){
	for(int i=2;i<=min(n,m);i+=1){
		if(n%i==0 && m%i==0){
			return i;
		}
	}
	return 1;
}
int main()
{
	ll n,i=0;
	scanf("%lld",&n);
	ll arr[n]={0};
	for(i=0;i<n;i++){
		scanf("%lld",&arr[i]);
	}	
	if(isDecrease(arr,n)){
		ll p=totalSum(arr,n);
		ll q=subSum(arr,n);
		if(gcd(p,q)==1){
			printf("A-sequence\n");
		}else{
			printf("NOT A-sequence\n");
		}

	}else{
		printf("NOT A-sequence\n");
	}
}