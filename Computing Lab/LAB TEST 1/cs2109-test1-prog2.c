#include<stdio.h>
// int row,col;
void S(int *a,int *b){
	int temp=*a;*a=*b;*b=temp;
}
void rev(int *x,int start,int end){
	while(start<=end){
		S(&x[start],&x[end]);
		start+=1;end-=1;
	}
}
void rotationColck(int matrix[1001][1001],int pos,int row,int col){
	int X[1001];
	pos%=(col+1);
	for(int i=0;i<row;i+=1){
		for(int j=0;j<col-pos;j+=1){
			X[j]=matrix[i][j];
		}
		for(int j=col-pos;j<col;j+=1){
			matrix[i][j-col+pos]=matrix[i][j];
		}
		for(int j=pos;j<col;j+=1){
			matrix[i][j]=X[j-pos];
		}
	}
	for(int i=0;i<row;i+=1){
		for(int j=0;j<col;j+=1){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}
void rotateAntiColck(int matrix[1001][1001],int pos,int row,int col){
	int ans[row][col];
        // if(pos==col){return matrix;}
	if(pos>col){
		pos%=col;
	}
	for(int i = 0; i<row; i++){
		int x = pos;
		for(int j = 0; j<col; j++){
			ans[i][j] = matrix[i][x];
			x++;
			if(x > (col-1)){x=0;}
		}
	}
	for(int i=0;i<row;i+=1){
		for(int j=0;j<col;j+=1){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int row,col;
	scanf("%d%d",&row,&col);
	int matrix[1001][1001];
	for(int i=0;i<row;i+=1){
		for(int j=0;j<col;j+=1){
			scanf("%d ",&matrix[i][j]);
		}
	}
	// for(int i=1;i<=row;i+=1){
	// 	for(int j=1;j<=col;j+=1){
	// 		printf("%d ",matrix[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// char ch[1000];scanf("%[^\n]%*c",ch);printf("%s",ch);
	char ch;scanf("%c",&ch);
	int pos,layer;scanf("%d %d",&pos,&layer);
	layer-=1;
	// printf("%c",ch);
	// // scanf("%d%d",&pos,&layer);
	// printf("%c %d %d",ch,pos,layer);
	int temp[1001][1001];int x=0;
	for(int i=layer;i<row-layer+1;i++){
		int y=0;
		for(int j=layer;j<col-layer+1;j+=1){
			temp[x][y++]=matrix[i][j];
		}
		x+=1;
	}
	if(ch=='A'){
		rotationColck(temp,pos,row,col);
	}else{
		// printf("Anti");
		rotateAntiColck(temp,pos,row,col);
	}
}