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
		void addbottom(int val){
			if(head==NULL)
			{
			addtop(val);
			return;
		    }
		    node *ele=new node;
		    ele->data=val;
		    ele->next=NULL;
		    node *temp=head;
		    while(temp->next!=NULL){
		    	temp=temp->next;
			}
			temp->next=ele;
			ele->previous=temp;
		}
		void addbefore(int val, int sval){
			node *ele=new node;
			ele->data=val;
			node *temp=head;
			while(temp->next!=NULL && temp->data!=sval)
			{
				temp=temp->next;
			}
			if(temp->data==sval)
			{if(temp->next!=NULL){
				ele->next=temp->next;
			}
			else {
				ele->next=NULL;
			}
			
				temp->next=ele;
				ele->previous=temp;
			}
			else
				{
				cout<<"number was not found..."<<endl;
		        delete ele;
		}
	}
        void addafter(int val,int sval){
        	node *ele=new node;
        	ele->data=val;
        	node *temp=head;
        	while(temp->next!=NULL && temp->data!=sval)
        	{
        		temp=temp->next;
			}
			if(temp->next!=NULL){
				if(temp->previous==NULL){
					ele->previous=NULL;
				}
				else
				  ele->previous=temp->previous;
				  
			    ele->next=temp;
			    temp->previous->next=ele;
			    temp->previous=ele;
			}
			else
				cout<<"The number was not found.."<<endl;
		}
		void deltop(){
			node *temp=head;
			head=head->next;
			delete temp;
			head->previous=NULL;
		}  
		void delbottom(){
			node *save=head;
			node *temp=head;
			while(temp->next!=NULL)
			{
				save=temp;
				temp=temp->next;
			}
			delete temp;
			save->next=NULL;
		}
		void delbefore(int sval){
			node *temp=head;
			while(temp->next!=NULL && temp->data!=sval)
		{
			temp=temp->next;
		}
		if(temp->next!=NULL){
			node *del=temp;
			del=del->next;
			if(del->next!=NULL)
			temp->next=del->next;
			else 
			temp->next=NULL;
			
			cout<<"The number being deleted is "<<del->data<<endl;
			delete del;
		}
		else
		cout<<"Number not found"<<endl;
}
        void delafter(int sval) {
    node *temp = head;
    while (temp->next != NULL && temp->data != sval) {
        temp = temp->next;
    }
    if (temp->next != NULL) {
        node *del = temp->previous;
        if (del->previous != NULL) {
            temp->previous = del->previous;
            del->previous->next = temp;
        } else {
            temp->previous = NULL;
            head=temp;
        }

        cout << "The number being deleted is " << del->data << endl;
        delete del;
    } else {
        cout << "Number not found" << endl;
    }
}

	void display(){
		node *temp =head;
		while(temp!=NULL){
			cout<<"The vale is "<<temp->data<<endl;
			temp=temp->next;
		}
		cout<<endl;
	}
};


int main()
{
	DoublyLinkedList dl;
	dl.addtop(2);
	dl.addtop(3);
	dl.addtop(5);
	dl.addtop(7);
	dl.addbottom(1);
	dl.addbottom(0);
	dl.display();
	
	dl.addbefore(4,5);
	dl.addafter(6,5);
	dl.display();
	
	dl.delbottom();
	dl.deltop();
	dl.delafter(5);
	dl.delbefore(6);
	
	dl.display();
	
	return 0;
}
