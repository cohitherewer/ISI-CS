/*ROLL NUMBER: cs2109
DATE: 12.12.2021
Problem Description:
	Write a C program to read two matrices A, B and print
	A-b & A*B
*/
#include<stdio.h>
#define ll long long
int main()
{
	int rowA,colA;scanf("%d %d",&rowA,&colA);
	int A[rowA][colA];
	for(int i=0;i<rowA;i+=1){
		for(int j=0;j<colA;j+=1){
			scanf("%d",&A[i][j]);
		}
	}
	int rowB,colB;scanf("%d %d",&rowB,&colB);
	int B[rowB][colB];
	for(int i=0;i<rowB;i+=1){
		for(int j=0;j<colB;j+=1){
			scanf("%d",&B[i][j]);
		}
	}
	// substraction
	printf("A-B:\n");
	if(rowB!=rowA || colA!=colB){printf("Invalid for subtraction\n");}
	else{
		for(int i=0;i<rowA;i++){
			for(int j=0;j<colA;j++){
				printf("%d ",A[i][j]-B[i][j]);
			}
			printf("\n");
		}
	}
	// multiplication
	printf("A*B: \n");
	if(colA!=rowB){
		printf("Invalid for multiplication\n");
	}else{
		for(int i=0;i<rowA;i++){
			// ll value=0;
			for(int j=0;j<colA;j++){
				ll value=0;
				for(int k=0;k<colB;k+=1){
					value+=(ll)A[i][j]*(ll)B[j][k];
				}
				printf("%lld ",value);
			}
			printf("\n");
		}
	}
}