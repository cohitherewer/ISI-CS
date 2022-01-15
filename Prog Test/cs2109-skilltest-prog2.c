#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int len(char *string){
	int count=0;
	while(string[count]!='\0'){
		count+=1;
	}
	return count;
}
bool isSame(char *word,int index, char *string){
	for(int i=0;i<index;i+=1){
		if(word[i]!=string[i]){
			return false;
		}
	}
	return true;
}
int main(int argc,char *argv[])
{
	char input[100001];
	char c;int length=0;
	FILE *fp;
	fp=fopen(argv[1],"r");
	if(fp==NULL){
		exit(0);
	}else{
		while((c=fgetc(fp))!=EOF){
			input[length]=c;length+=1;
		}
	}
	length-=1;
	fclose(fp);
	fp=fopen(argv[1],"w");
	char *string=argv[2],*prefix=argv[3];
	int x=len(string),y=len(prefix);
	int i=0;
	// printf("%s%s%s\n",input,string,prefix);
	// printf("%d %d %d\n",x,y,length);
	for(;i<length;i++){
		if(input[i]!=string[0]){
			fprintf(fp,"%c",input[i]);
		}else{
			bool flag=false;
			int j=0;
			for(;j<x;j++){
				if(input[i+j]!=string[j]){
					flag=true;
					break;
				}
			}
			// printf("flag=%d",flag);
			if(flag==true){
				fprintf(fp,"%c",input[i]);
			}else{
				for(j=0;j<y;j+=1){
					fprintf(fp,"%c",prefix[j]);
				}
				for(j=0;j<x;j+=1){
					fprintf(fp,"%c",string[j]);
				}
				i+=(x-1);
			}
		}
	}
	fclose(fp);
}