#include<stdio.h>
#define ll long long
ll max(ll a,ll b){
	if(a>b)return a;
	else return b;
}
ll min(ll a,ll b){
	if(a<b){
		return a;
	}else return b;
}
ll generateCombo(ll combo[10000]){
	ll h=0,m=0;
	ll index=0;
	for(h=0;h<12;h+=1){
		for(m=0;m<60;m+=1){
			ll x=60*h+m;
			ll y=12*m;
			combo[index]=2*(max(x,y)-min(x,y));index+=1;
			combo[index]=2*(1400-max(x,y)+min(x,y));index+=1;
		}
	}
	return index;
}
ll abs(ll a){
	if(a>0)return a;
	else return -a;
}
int main()
{
	ll combo[10000];
	ll m,n;
	scanf("%lld%lld",&m,&n);
	ll index=generateCombo(combo);
	bool flag=false;int i=0;
	for(i=0;i<index;i+=1){
		if(abs(combo[i]*n)==abs(720*m)){
			flag=true;
			break;
		}
	}
	char ans[]="VALID";
	if(flag==false){
		printf("IN");
	}
	printf("%s\n",ans);
}