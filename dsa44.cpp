#include<iostream>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};
class BST{
	node *root;
	public:
		BST(){
			root=NULL;
		}
	void insert(int val)
	{
		node *ele=new node;
		ele->data=val;
		ele->left=NULL;
		ele->right=NULL;
		
		node *prev;
		if(root==NULL){
			root=ele;
			return;
		}
		node *ptr=root;
		while(ptr!=NULL){
			prev=ptr;
			if(ptr->data==ele->data)
			{
				cout<<"This element cannot be added: "<<ele->data<<endl;
				return;
			}
			else if(ele->data<ptr->data){
				ptr=ptr->left;
			}
			else
			ptr=ptr->right;
		}
		if(ele->data>prev->data){
			prev->right=ele;
		}
		else{
			prev->left=ele;
		}
	}
	node* reroot(){
		return root;
	}
	void preorder(node *temp){
		if(temp!=NULL){
			cout<<"The preorder value is "<<temp->data<<endl;
			if(temp->left!=NULL)
            preorder(temp->left);

			if(temp->right!=NULL)
			preorder(temp->right);
		}
		else
		cout<<"The tree is empty..."<<endl;
	}
	
	void inorder(node *temp)
	{
		if(temp!=NULL){
			
			if(temp->left!=NULL)
			inorder(temp->left);
			
			cout<<"The inorder value is "<<temp->data<<endl;
			
			if(temp->right!=NULL)
			inorder(temp->right);
		}
		else
		cout<<"The tree is empty.."<<endl;
	}
	void postorder(node *temp){
		if(temp!=NULL){
			
			if(temp->left!=NULL)
			postorder(temp->left);
			
			if(temp->right!=NULL)
			postorder(temp->right);
			
			cout<<"The postorder value is "<<temp->data<<endl;
		}
		else
		cout<<"The tree is empty."<<endl;
	}
	
	node* minval(node *temp){
		
		node* ptr=temp;
		while(ptr && ptr->left!=NULL)
		ptr=ptr->left;
		return ptr;
	}
	
	node* deletenode(node *root, int value){
		if(root==NULL)
		return root;
		
		if(value<root->data)
		{
			root->left=deletenode(root->left,value);
		}
		else if(value>root->data)
		{
			root->right=deletenode(root->right,value);
		}
		else{
			node *temp;
			if(root->right==NULL && root->left==NULL){
				delete root;
				root=NULL;
			}
			else if(root->left==NULL){
				temp=root;
				root=root->right;
				delete temp;
			}
			else if(root->right==NULL){
				temp=root;
				root=root->left;
				delete temp;
			}
			else{
				temp= minval(root->right);
				root->data=temp->data;
				root->right= deletenode(root->right,root->data);
			}
		}
		return root;
	}
};

int main()
{
	BST t1;
	t1.insert(3);
	t1.insert(4);
	t1.insert(5);
	t1.insert(2);
	t1.insert(8);
	t1.insert(0);
	t1.insert(6);
	t1.insert(8);
	
	node* ptr=t1.reroot();
	
	t1.preorder(ptr);
	cout<<endl;
	t1.inorder(ptr);
	cout<<endl;
	t1.postorder(ptr);
	cout<<endl;
	
	t1.deletenode(ptr,6);
	t1.inorder(ptr);
	
	return 0;
}
