/*
 * Name: Abhinaba Chakraborty
 * Roll No: cs2109
 * Date: 15.1.2021
 * Program Description: Write a program in C++ to show type conversion from string of numeric characters to integer,
without using the built-in atoi() function. For example, if the string object S1 is "2021", it should be
converted to 2021 as integer if we write int i=S1;
 */

#include<bits/stdc++.h>
using namespace std;
class STRING{
private:
	string s;
	int len;
public:
	STRING()=delete;
	STRING(string X){
		this->s=X;this->len=X.size();
	}
	operator int(){
		bool flag=false;
		int start=0,ans=0;
		if(s[0]=='-')flag=true;
		else if(s[0]=='+')start=1;
		if(flag)start=1;
		for(int i=start;i<len;++i){
			if(s[i]>='0' and s[i]<='9')ans=ans*10+(s[i]-'0');
			else {
				printf("INVALID INPUT(RETURNING RANDOM NUMBER)\n");
				return rand();
			}
		}
		if(flag)ans*=-1;
		return ans;
	}
};			
int main()
{
	string input;cin>>input;
	STRING X(input);
	int i=X;
	printf("%d\n",i);
}
