#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int val;
	int ans;
	struct Node* right;
	struct Node* left;
};
typedef struct Node node;
node* newnode(int val){
	node* n;
	n=(node*)calloc(1,sizeof(node));
	n->val=val;
	n->ans=0;
	n->right = NULL;
	n->left =NULL;
}
int search(node* root,int s){
	 if (root->val>s)
	{	
		root->ans=0;
		return 0;
	}
	else{
		s=s-root->val;
		int l=0,r=0;
		if (root->left!=NULL)
		{
			l = search(root->left,s);
		}
		else if (s==0)
		{
			l=1;
		}
		if (root->right!=NULL)
		{
			r = search(root->right,s);
		}
		else if (s==0)
		{
			r==1;
		}
		
		root->ans=l+r;
		return l+r;
	}
}
void print(node* root){
	while(root->ans>0){
		cout<<root->val<<" ";
		if ((root->left!=NULL)&&(root->left->ans>0))
		{
			print(root->left);
		}
		else if((root->right!=NULL)&&(root->right->ans>0)){
			print(root->right);
		}
		root->ans--;
		//cout<<endl;
	}
}
int main()
{	cout<<"give Input sum"<<endl;
	node* root = newnode(10);
	root->left= newnode(28);
	root->right=newnode(13);
	root->right->left=newnode(14);
	root->right->right=newnode(15);

	root->right->left->left=newnode(21);
	root->right->left->right=newnode(22);
	root->right->right->right=newnode(24);
	root->right->right->left=newnode(23);

	int sum,npaths;
	cin>>sum;
	npaths=search(root,sum);
	cout<<npaths<<" paths found!"<<endl;
	while(root->ans>0){
		cout<<root->val<<" ";
		if ((root->left!=NULL)&&(root->left->ans>0))
		{
			print(root->left);
		}
		else if((root->right!=NULL)&&(root->right->ans>0)){
			print(root->right);
		}
		root->ans--;
		cout<<endl;
	}
	return 0;
}