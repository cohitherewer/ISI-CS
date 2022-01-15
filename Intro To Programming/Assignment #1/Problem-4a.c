/*
NAME: ABHINABA CHAKRABORTY
ROLL NUMBER: cs2109
DATE: 12.12.2021
Problem Description:
	Write a program to print the following outputs using for loop
	****
	 ***
	  **
	   *
*/
#include<stdio.h>
int main()
{
	int n=4;
	for(int i=4;i>=1;i-=1){
		for(int j=1;j<=4-i;j+=1){
			printf(" ");
		}
		for(int j=1;j<=i;j+=1){
			printf("*");
		}
		printf("\n");
	}
}