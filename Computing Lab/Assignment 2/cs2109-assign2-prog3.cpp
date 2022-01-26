#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
#define N 1000000

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
void func(struct TreeNode *root,vector<vector<pair<int,int>>>& v,vector<pair<int,int>> T,int dir){
	if(root==NULL)return;
	T.push_back(make_pair(root->data,dir));
	if(root->left==NULL && root->right==NULL){
		v.push_back(T);
	}
	if(root->left)func(root->left,v,T,0);
	if(root->right)func(root->right,v,T,1);
}
void levelOrder(struct TreeNode *root){
	vector<vector<pair<int,int>>> v;
	vector<pair<int,int>> x;x.push_back(make_pair(root->data,-1));
	if(root->left)func(root->left,v,x,0);
	if(root->right)func(root->right,v,x,1);
	vector<vector<pair<int,int>>> ans;int zCount=0;
	for(int i=0;i<(int)v.size();++i){
		//for(auto it:v[i])cout<<it.first<<" ";
		//cout<<"Path: ";int count=0;
		if((int)v[i].size()<=2)continue;
		else{
			for(int j=0;j<(int)v[i].size();){
				if(v[i][j].second==1 && v[i][j+1].second==0 && v[i][j+2].second==1){++count;j+=3;}
				else j+=1;
			}
			if(count==0)continue;
			if(count>zCount){
				ans.clear();ans.push_back(v[i]);zCount=count;
			}else if(count==zCount && ans.size()>0 && ans[0].size()>v[i].size()){
				ans.clear();ans.push_back(v[i]);
			}else if(ans[0].size()==v[i].size()){
				ans.push_back(v[i]);
			}	
		}
		//cout<<endl;
	}
	for(int i=0;i<(int)ans.size();++i){
		for(auto it:ans[i])cout<<it.first<<" ";
		cout<<endl;
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


