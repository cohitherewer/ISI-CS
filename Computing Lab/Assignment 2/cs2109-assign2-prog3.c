#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
//#include<bits/stdc++.h>
//using namespace std;
#define N 1000000
//Used for creating the tree
int V[N]={0};
int n;
struct TreeNode{
	int data;
	struct TreeNode *left;struct TreeNode *right;
};
struct TreeNode* createBSTutil(int *index,int X,int Y){
	if(*index>=n || V[*index]<X || V[*index]>Y)return NULL;
	struct TreeNode* root=(struct TreeNode *)malloc(sizeof(struct TreeNode *));
	root->data=V[(*index)++];root->left=NULL,root->right=NULL;
	root->left=createBSTutil(index,X,root->data-1);
	root->right=createBSTutil(index,root->data+1,Y);
	return root;
}
struct TreeNode* createBST(){
	if(n==0)return NULL;
	int index=0;
	return createBSTutil(&index,INT_MIN,INT_MAX);
}
//Code to find out number path with max no overlapping z pattern
struct pair{int val,dir;};typedef struct pair p;
int leaves(struct TreeNode *root){
	if(root==NULL)return 0;
	else if(root->left==NULL && root->right==NULL)return 1;
	return (root->left?leaves(root->left):0)+(root->right?leaves(root->right):0);
}
void FUNC(struct TreeNode *root,p **v,int *vIndex,p *x,int xIndex,int dir,int *size){
	if(root==NULL)return;
	x[xIndex].val=root->data,x[xIndex++].dir=dir;
	if(root->left==NULL && root->right==NULL){
		size[*vIndex]=xIndex;
		v[*vIndex]=(p*)malloc(xIndex*sizeof(p*));
		int i=0;for(;i<xIndex;++i){v[*vIndex][i].val=x[i].val;v[*vIndex][i].dir=x[i].dir;}
		*vIndex+=1;
		return;
	}
	if(root->left)FUNC(root->left,v,vIndex,x,xIndex,0,size);
	if(root->right)FUNC(root->right,v,vIndex,x,xIndex,1,size);
}
void levelOrder(struct TreeNode *root){
	int C=leaves(root);
	p **v;v=(p **)malloc(C*sizeof(p *));
	int *size=(int *)calloc(C,sizeof(int *));
	p *x=(p*)malloc(n*sizeof(p *));x[0].val=root->data;x[0].dir=-1;
	int vIndex=0;
	if(root->left)FUNC(root->left,v,&vIndex,x,1,0,size);
	if(root->right)FUNC(root->right,v,&vIndex,x,1,1,size);
	//printf("vIndex %d\n",vIndex);
	int i=0;
	//for(;i<C;i++){
		//int j=0;for(;j<size[i];++j)printf("%d %d ",v[i][j].val,v[i][j].dir);
		//printf("\n");
	//}
	
	//**v contains all the paths along with direction and size[i] is the corresponding size
	int zCount=0,zSize=0;
	int *CA=(int *)calloc(C,sizeof(int *));
	for(;i<C;i++){
		if(size[i]<=2){CA[i]=0;}
		else{
			int j=3,count=0;
			for(;j<size[i];){
				if(v[i][j-2].dir==1 && v[i][j-1].dir==0 && v[i][j].dir==1){++count;j+=3;}
				else ++j;
			}
			if(count>zCount){zCount=count;zSize=size[i];}
			else if(count==zCount){
				if(size[i]<zSize)zSize=size[i];
			}
			CA[i]=count;
		}
	}
	if(zCount==0){printf("NIL\n");return;}
	i=0;
	for(;i<C;++i){
		if(zCount==CA[i] && size[i]==zSize){
			int j=0;for(;j<size[i]-1;j++)printf("%d-",v[i][j].val);
			printf("%d\n",v[i][size[i]-1].val);printf("%d\n",zCount);
		}
	}
}
int main()
{
	scanf("%d",&n);int a=0;
	for(;a<n;++a)scanf("%d",&V[a]);
	struct TreeNode* root=createBST();
	//postOrder(root);
	if(root==NULL){
		printf("0\n");return 0;
	}
	levelOrder(root);
}


