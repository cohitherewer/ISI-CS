/*ROLL NUMBER: cs2109
DATE: 12.12.2021
Problem Description:
	Print pascals triangle for 9 rows
*/
#include<stdio.h>
#define ll long long
int main()
{
	int n=9;
	ll arr[9][51]={0};
	arr[0][0]=1,arr[1][0]=1,arr[1][1]=1;
	for(int i=2;i<9;i+=1){
		arr[i][0]=1;
		int j=1;
		for(;arr[i-1][j]!=0;j+=1){
			arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
		}
		arr[i][j]=1;
	}
	for(int i=0;i<9;i++){
		for(int j=0;arr[i][j]!=0;j++){
			printf("%lld ",arr[i][j]);
		}
		printf("\n");
	}
}