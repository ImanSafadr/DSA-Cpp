#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
	node *previous;
};
class DoublyLinkedList{
	private:
		node *head;
	public:
	    DoublyLinkedList(){
	    	head=NULL;
		}	
		void addtop(int val){
			node *ele= new node;
			ele->data=val;
			ele->previous=NULL;
			if(head==NULL)
			{
				ele->next=NULL;
			}
			else{
				ele->next=head;
				head->previous=ele;
			}
				head=ele;
				cout<<"The value "<<val<<" has been entered"<<endl;
		}
	
	void display(){
		node *temp =head;
		while(temp!=NULL){
			cout<<"The vale is "<<temp->data<<endl;
			temp=temp->next;
		}
		cout<<endl;
	}
	int pop(){
		if (head==NULL)
		{
			cout<<"The linklist is empty"<<endl;
			return -1;
		}
		node *temp=head;
		int data= head->data;
		head=head->next;
		delete temp;
		return data;
	}
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
		ele->previous=NULL;
		ele->next=NULL;
		
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
				ptr=ptr->previous;
			}
			else
			ptr=ptr->next;
		}
		if(ele->data>prev->data){
			prev->next=ele;
		}
		else{
			prev->previous=ele;
		}
	}
	node* reroot(){
		return root;
	}
	
	
	void inorder(node *temp)
	{
		if(temp!=NULL){
			
			if(temp->previous!=NULL)
			inorder(temp->previous);
			
			cout<<"The inorder value is "<<temp->data<<endl;
			
			if(temp->next!=NULL)
			inorder(temp->next);
		}
		else
		cout<<"The tree is empty.."<<endl;
	}
	
};
    

int main()
{
	DoublyLinkedList dl;
	dl.addtop(2);
	dl.addtop(3);
	dl.addtop(5);
	dl.addtop(7);
	dl.addtop(9);
	dl.addtop(8);
	 
	dl.display();

    BST bs;
	bs.insert(dl.pop());	
	bs.insert(dl.pop());	
	bs.insert(dl.pop());	
	bs.insert(dl.pop());	
	bs.insert(dl.pop());	
	bs.insert(dl.pop());	

	
	node* po=bs.reroot();
	bs.inorder(po);	
	return 0;
}
