#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#define N 1000000

int V[N]={0};
struct TreeNode{
	int data;
	struct TreeNode *left;struct TreeNode *right;
	//TreeNode(int x):val(x),left(NULL),right(NULL){}
};
struct TreeNode* createBSTutil(int n,int *index,int X,int Y){
	if(*index>=n || V[*index]<X || V[*index]>Y)return NULL;
	struct TreeNode* root=(struct TreeNode *)malloc(sizeof(struct TreeNode *));
	root->data=V[(*index)++];root->left=NULL,root->right=NULL;
	root->left=createBSTutil(n,index,X,root->data-1);
	root->right=createBSTutil(n,index,root->data+1,Y);
	return root;
}
struct TreeNode* createBST(int n){
	if(n==0)return NULL;
	int index=0;
	return createBSTutil(n,&index,INT_MIN,INT_MAX);
}
//void postOrder(struct TreeNode* root){
	//if(root==NULL)return;
	//postOrder(root->left);
	//postOrder(root->right);
	//printf("%d ",root->data);
//}
int A[2][N]={0};
void zPattern(struct TreeNode *root,int index,int *x,char dir,int *f){
	A[index][(*x)++]=root->data;
	if(root->left==NULL && root->right==NULL){
		if((*x)>2)*f=1;
		return;
	}
	if(dir=='R' && root->right!=NULL)zPattern(root->right,index,x,'L',f);
	else if(dir=='L' && root->left!=NULL)zPattern(root->left,index,x,'R',f);
	else return;
}
int main()
{
	int n;scanf("%d",&n);int a=0;
	for(;a<n;++a)scanf("%d",&V[a]);
	struct TreeNode* root=createBST(n);
	//postOrder(root);
	if(root==NULL){
		printf("0\n");return 0;
	}
	//A[0][0]=root->data;A[1][0]=root->data;
	int i=0,j=0,f=0,g=0;
	if(root->left){
		zPattern(root,0,&i,'L',&f);
	}
	if(root->right){
		zPattern(root,1,&j,'R',&g);
	}
	if(f==1 && g==1){
		if(i>j){
			int p=0;
			for(;p<j;++p)p<j-1?printf("%d-",A[1][p]):printf("%d\n",A[1][p]);
			printf("%d\n",j-1);
		}else if(j>i){
			int p=0;
			for(;p<i;++p)p<i-1?printf("%d-",A[0][p]):printf("%d\n",A[0][p]);
			printf("%d\n",i-1);
		}else{
			int p=0;
			for(;p<i;++p)p<i-1?printf("%d-",A[0][p]):printf("%d\n",A[0][p]);
			printf("%d\n",i-1);
			p=0;
			for(;p<j;++p)p<j-1?printf("%d-",A[1][p]):printf("%d\n",A[1][p]);
			printf("%d\n",j-1);
		}
	}else if(f==1){
		int p=0;
		for(;p<i;++p)p<i-1?printf("%d-",A[0][p]):printf("%d\n",A[0][p]);
		printf("%d\n",i-1);
	}else if(g==1){
		int p=0;
		for(;p<j;++p)p<j-1?printf("%d-",A[1][p]):printf("%d\n",A[1][p]);
		printf("%d\n",j-1);
	}else{
		printf("0\n");
	}
}
