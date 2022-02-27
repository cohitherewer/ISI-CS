#include<bits/stdc++.h>
using namespace std;
class drinkInfo{
protected:
	int quant[5];
	int price[5];
public:
	drinkInfo(){
		for(int i=0;i<5;++i){quant[i]=(int)rand();}
		for(int i=0;i<5;++i){price[i]=(int)rand() %100;}
	}
	int priceDisplay(int option){
		return price[option-1];
	}
};
class balanceInfo{
protected:
	int totalBal;
	int tempBal;
public:
	balanceInfo()=delete;
	balanceInfo(int cap){
		totalBal=cap;
		tempBal=0;
	}
	void updateBal(int x){
		totalBal+=x;
	}
	void updateTemp(int a){
		tempBal+=a;
	}
	int getTemp(){return tempBal;}
	void resetTemp(){tempBal=0;}
};
int main()
{
	balanceInfo b(0);
	while(true){
		drinkInfo p;
		cout<<"*******Welcome *********\n";
		cout<<"\nTo select an item, enter\n";
		cout<<"\n1 for Plain Tea\n2 for Plain Coffee\n3 for Ice Tea\n4 For Ice Coffee\n5 For Lemon Tea\n6 to exit\n";
		int option;cin>>option;
		if(option==6){
			cout<<"Thanks for visiting....Bye\n";
			return 0;
		}else if(option>6 || option<1){
			printf("\nInvalid option\n");continue;
		}
		printf("\nPlease deposite Rs. %d:\n", p.priceDisplay(option));
		int pay=0;int count=0;
		while(true){
			scanf("%d",&pay);
			b.updateTemp(pay);
			if(b.getTemp()>p.priceDisplay(option)){
				cout<<"\nCollect Extra Money you have given\n";
				cout<<"\nCollect your item at the bottom and enjoy.\n";
				b.resetTemp();b.updateBal(p.priceDisplay(option));break;
			}else if(b.getTemp()==p.priceDisplay(option)){
				cout<<"\nCollect your item at the bottom and enjoy.\n";
				b.resetTemp();b.updateBal(p.priceDisplay(option));break;
			}else{
				if(count==0){
					cout<<"\nPlease deposite another Rs. "<<p.priceDisplay(option)-b.getTemp()<<endl;count+=1;
				}else{
					cout<<"\nThe amount is not sufficient. Collect your deposited amount\n";
					b.resetTemp();break;
				}
			}
		}
		for(int i=0;i<15;++i)cout<<"*";
		cout<<endl;
	}
}
