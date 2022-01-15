/*ROLL NUMBER: cs2109
DATE: 12.12.2021
Problem Description:
	A file named “IPDATA” contains a series of integer number. Write program to read
these numbers and then write all odd number to a file to be called “OPODD” and all even numbers
to a file called “OPEVEN”.
*/
#include<stdio.h>
#define ll long long
int main()
{
	FILE *data=fopen("IPDATA","r");
	FILE *even=fopen("OPEVEN","w");
	FILE *odd=fopen("OPODD","w");
	char c=getc(data);
	while(c!=EOF){
		ll num=0;bool f=false;
		while(c>='0' && c<='9'){
			num=num*10+(c-'0');
			c=getc(data);f=true;
		}
		if(num%2==0 && f==true){
			fprintf(even,"%lld ",num);
		}else if(num%2==1 && f==true){
			fprintf(odd,"%lld ",num);
		}else{
			c=getc(data);
		}
	}
	fclose(data),fclose(even),fclose(odd);
}