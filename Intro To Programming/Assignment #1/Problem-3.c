/*
NAME: ABHINABA CHAKRABORTY
ROLL NUMBER: cs2109
DATE: 12.12.2021
Problem Description:
	Do the task given in Problem-1 using switch case.
*/
#include<stdio.h>
int main()
{
	int num;scanf("%d",&num);
	char grade='F';
	switch(num){
		case 80 ... 100:grade='A';break;
		case 60 ... 79:grade='B';break;
		case 50 ... 59:grade='C';break;
		case 40 ... 49:grade='D';break;
		default:grade='F';break;
	}
	printf("%c\n",grade);

}