/*
NAME: ABHINABA CHAKRABORTY
ROLL NUMBER: cs2109
DATE: 12.12.2021
Problem Description:
	Write a C program to read a matrix of size m X n and prints
	its transpose.
*/
#include<stdio.h>
int main()
{
	int row,cols;scanf("%d %d ",&row,&cols);
	int arr[row][cols];
	for(int i=0;i<row;i+=1){
		for(int j=0;j<cols;j+=1){
			scanf("%d",&arr[i][j]);
		}
	}
	// transpose
	for(int i=0;i<cols;i++){
		for(int j=0;j<row;j+=1){
			printf("%d ",arr[j][i]);
		}
		printf("\n");
	}
}