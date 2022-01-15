/*ROLL NUMBER: cs2109
DATE: 12.12.2021
Problem Description:
	Write program that compares two files and indicates whether these are equal or not.
*/
#include<stdio.h>
int main()
{
	FILE *x=fopen("1.txt","r");
	FILE *y=fopen("2.txt","r");

	if(x==NULL || y==NULL){
		printf("Something wrong\n");
		fclose(x),fclose(y);
		return 0;
	}else{
		char a=getc(x),b=getc(y);
		while(a!=EOF && b!=EOF){
			if(a!=b){
				printf("Files are not equal");
				fclose(x),fclose(y);
				return 0;
			}else{
				a=getc(x),b=getc(y);
			}
		}
	}
	printf("The files are equal\n");
	fclose(x),fclose(y);
}