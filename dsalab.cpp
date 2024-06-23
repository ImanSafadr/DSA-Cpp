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
       
		void deltop(){
			node *temp=head;
			head=head->next;
			delete temp;
			head->previous=NULL;
		}  

	void display(){
		node *temp =head;
		while(temp!=NULL){
			cout<<"The vale is "<<temp->data<<endl;
			temp=temp->next;
		}
		cout<<endl;
	}
	void even(DoublyLinkedList dl){
		node* temp=head;
		while(temp!=NULL){
			if(temp->data%2==0){
			dl.addtop(temp->data);
		}
			temp=temp->next;
		}
	}
		void odd(DoublyLinkedList dl){
		node* temp=head;
		while(temp!=NULL){
			if(temp->data%2!=0){
			dl.addtop(temp->data);
		}
			temp=temp->next;
		}
	}
};


int main()
{
	DoublyLinkedList dl,dl1,dl2;
	dl.addtop(2);
	dl.addtop(3);
	dl.addtop(5);
	dl.addtop(7);
	dl.addtop(23);
	dl.addtop(22);

	dl.display();

    cout<<"For the even numbers"<<endl;
    dl.even(dl1);
    dl1.display();
    cout<<endl;
    
    cout<<"For the odd numbers"<<endl;
	dl.odd(dl2);
    dl2.display();
    cout<<endl;
    
	return 0;
}
