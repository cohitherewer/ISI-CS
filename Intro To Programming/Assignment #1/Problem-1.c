/*
NAME: ABHINABA CHAKRABORTY
ROLL NUMBER: cs2109
DATE: 12.12.2021
Problem Description:
	Consider the grading of the students in an academic institution. The grading is according to the
	following rules.
	Average marks Grade
	80<=m<=100		A
	60<=m<80		B
	50<=m<60		A
	40<=m<50		A
	0<=m<40		A
Now, write a C program that takes as input the average marks of any student and prints his/her
grade as per the given rule. [Take help of else if ladder.]
*/
#include<stdio.h>
int main()
{
	int num;scanf("%d",&num);
	char grade='F';
	if(num>=80 && num<=100)grade='A';
	else if(num>=60 && num<80)grade='B';
	else if(num>=50 && num<60)grade='C';
	else if(num>=40 && num<50)grade='D';

	printf("%c\n",grade);
}