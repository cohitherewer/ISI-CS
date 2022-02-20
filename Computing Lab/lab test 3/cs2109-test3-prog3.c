#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define N 100000
struct TreeNode{
	int val;
	struct TreeNode *left,*right;
};
struct TreeNode* buildTree(int postorder[], int inorder[], int postStart, int postEnd,int inStart, int inEnd) {
	if(postStart > postEnd || inStart > inEnd)return NULL;
	struct TreeNode* root = malloc(sizeof(struct TreeNode));
	root->val = postorder[postEnd];
	int indx=inStart;
	for(int i = inStart; i <= inEnd; i++) {if(inorder[i] == root->val) {indx = i;break;}}
	root->left  = buildTree(postorder, inorder, postStart, postEnd - (inEnd - indx +  1),inStart, indx - 1);
	root->right = buildTree(postorder, inorder, postStart, postEnd - 1,indx + 1, inEnd);
	return root;
}
//struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
	//if(inorder == NULL || postorder == NULL)
		//return NULL;

	//return buildTree_r(postorder, inorder, 0, postorderSize - 1, 0, inorderSize - 1);
//}
struct TreeNode* newNode(int val) {
    struct TreeNode *temp = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    if(temp == NULL) return NULL;
    temp->left = NULL;temp->right = NULL;temp->val = val;
    return temp;
}
struct TreeNode* buildBST(int* pre, int x) {
    if(x<= 0) return NULL;
    if(x== 1) return newNode(pre[0]);
    struct TreeNode *root = newNode(pre[0]);
    struct TreeNode *temp = root;
    int i = 1;
    while(i < x) {
        if(temp->val > pre[i] && temp->left != NULL) {temp = temp->left;continue;} 
        else if(temp->val < pre[i] && temp->right != NULL) {temp = temp->right;continue;
        }else if(temp->val > pre[i] && temp->left == NULL) {temp->left = newNode(pre[i]);
        } else if(temp->val < pre[i] && temp->right == NULL) {temp->right = newNode(pre[i]);}
        temp = root;
        i++;
    }
    return root;
}
bool isMirror(struct TreeNode *S,struct TreeNode *T){
	if(S==NULL && T==NULL)return true;
	if(S==NULL || T==NULL)return false;
	return S->val==T->val && isMirror(S->left,T->right) && isMirror(S->right,T->left);
}
//void X(struct TreeNode *a){
	//if(a==NULL)return;
	//printf("%d ",a->val);
	//X(a->left);X(a->right);
//}
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	//printf("%d %d",x,y);
	
	int preorder[N];int i=0;for(;i<x;i++)scanf("%d",&preorder[i]);
	int postorder[N],inorder[N];
	i=0;for(;i<y;i++)scanf("%d",&inorder[i]);
	i=0;for(;i<y;i++)scanf("%d",&postorder[i]);
	
	struct TreeNode *T=buildTree(postorder,inorder,0,y-1,0,y-1);
	
	struct TreeNode *S=buildBST(preorder,x);
	//printf("tree");
	//X(T);
	//printf("bst");
	//X(S);
	if(isMirror(T,S)){
		printf("MIRROR TWIN\n");
	}else{
		printf("NOT MIRROR TWIN\n");
	}
}

