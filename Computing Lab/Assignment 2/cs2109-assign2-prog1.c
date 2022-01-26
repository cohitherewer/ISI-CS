#include<stdio.h>
#define N 200
#define ll long long int
ll POW(ll n,ll k){
	if(k==0)return 1;
	ll T=POW(n,k/2);
	return k%2==0?T*T:T*T*n;
}
int isValid(char A[],ll *p){
	int i=0;
	while(A[i]!='\0'){
		if(A[i]>='0' && A[i]<='9')*p=*p*10+(A[i++]-'0');
		else return 0;
	}
	return *p>0?*p:0;
}
int main()
{
	char X[N],Y[N];
	scanf("%s",X);scanf("%s",Y);
	printf("%s %s",X);
	ll a,b;
	if(isValid(X,&a) && isValid(Y,&b)){
		printf("%lld",POW(a,b));	
	}else{
		printf("INVALID INPUT");
	}
}
