/*---------------
 * NAME: ABHINABA CHAKRABORTY
 * ROLL NO: cs2109
 * ---------------*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Cuntomer{
	char id[9];int pass,balance;
} cust;
cust A[101];int index=0;
int F(char s[9],char x[9]){
	int i=0;for(;i<9;++i){
		if(s[i]!=x[i])return 0;
	}return 1;
}
int valid(char s[9],int id){
	int x=0;int j=0,i=0;
	for(;i<index;++i){
		if(F(A[i].id,s)){
			x=1;j=i;break;
		}
	}
	if(x==0){
		printf("LOGIN FAILED!ID does not exist");
		return -1;
	}
	if(A[j].pass==id)return j;
	else {
		printf("LOGIN FAILED! PASSWORD CORRECT");
	}
	return -1;
}
int validateID(char S[9]){
	return S[0]=='A' && S[1]=='B' && S[2]=='M' && S[3]=='0' && S[4]=='0' && S[5]=='1';
}
int validatePass(int x){
	int y=x;
	int cnt=0;while(y>0){cnt+=1;y/=10;}
	if(cnt!=4)return 0;
	else return 1;
}
void bankActions(int j){
	char op;
	while(1){
		printf("\na. Deposite Money\nb.Withdraw Money\nc. Check Balance\nd. Exit\n");
		scanf("%c",&op);
		scanf("%c",&op);
		if(op=='a'){
			printf("\nAmount of deposite:");int money;scanf("%d",&money);
			A[j].balance+=money;
			printf("\nAmount successfully deposited");
		}else if(op=='b'){
			printf("\nAmount of withdraw:");int money;scanf("%d",&money);
			if(A[j].balance<money){
				printf("\nInsufficient Balance\n");
			}else{
				A[j].balance-=money;
				printf("\nAmount withdrawl is successfull\n");
			}
		}else if(op=='c'){
			printf("\nYour balance is Rs. %d: \n",A[j].balance);
		}else if(op=='d'){
			printf("\nThanks for visiting.....Bye\n");
			exit(0);
		}else{
			printf("\nInvalid Choice\n");
		}
	}
}
		
int main()
{
	printf("Welcome!\n");
	int n;
	while(1){
		printf("\nPlease select an option from the menu below:\n");
		printf("\n1) Login\n2) Create New Account\n3) Quit\n");
		scanf("%d",&n);
		if(n==1){
			printf("\nPlease enter your id:");
			char s[9];scanf("%s",s);
			printf("\nPlease enter your password:");
			int p;scanf("%d",&p);
			if(valid(s,p)!=-1){
				printf("\nLOGIN SUCCESSFULL!");int j=valid(s,p);
				bankActions(j);
			}else{
				continue;
			}
		}else if(n==2){
			printf("\nPlease enter your id:");
			char s[9];scanf("%s",s);
			printf("\nPlease enter your password:");
			int p;scanf("%d",&p);
			if(validateID(s) && validatePass(p)){
				int i=0;
				for(;i<strlen(s);++i){
					A[index].id[i]=s[i];
				}
				A[index].pass=p;A[index].balance=0;index+=1;
				printf("\nThank You!The account has been created");
			}else if(!validateID(s) || !validatePass(p)){
				printf("\nThe Format for id or password wrong");
			}
		}else if(n==3){
			return 0;
		}else{
			printf("\nINVALID CHOICE\n");
		}
	}
		
}
