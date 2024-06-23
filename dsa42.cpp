#include<iostream>
using namespace std;

struct node{
	int data;
	node *link;
};
class Singlylinkedlist{
	private:
		node *head;
		public:
			Singlylinkedlist(){
				head=NULL;
			}
			void addlast(int val)
			{ 	node *ichi=new node;
				ichi->data=val;
				ichi->link=head;
				head=ichi;
			}
			void addfront(int val){
				node *ano=new node;
				ano->data=val;
				ano->link=NULL;
				if(head==NULL)
				head=ano;
				else{
				node *temp=head;	
				while(temp->link!=NULL){
					temp=temp->link;
				}
				temp->link=ano;	
			}
		}
		void addbefore(int val, int sval){
			node *ele =new node;
			ele->data=val;
			if(head==NULL){
			head=ele;
			return;
		}
			node *temp=head;
			while(temp->link!=NULL && temp->link->data!=sval){
				temp=temp->link;
			}
			if(temp->link!=NULL){
				ele->link=temp->link;
				temp->link=ele;
			}
			else {
			delete ele;
		cout<<"The number "<<sval<<" was not found..."<<endl;	
		}
		}
		void addafter(int val, int sval){
			node *ele =new node;
			ele->data=val;
			
			if(head==NULL){
			head=ele;
			return;
		}
			node *temp=head;
			while(temp->link!=NULL && temp->data!=sval){
				temp=temp->link;
			}
			
			if(temp->link!=NULL){
				ele->link=temp->link;
				temp->link=ele;
			}
			else {
			delete ele;
		cout<<"The number "<<sval<<" was not found..."<<endl;	
		}
		}
		void delafter(int sval){
			node *temp=head;
			node *ptr=head;
			if(head==NULL){
			cout<<"Deletion not possible ..."<<endl;
			return ; 	
			}
			while(temp!=NULL && ptr->data!=sval)
			{   ptr=temp;
				temp=temp->link;
			}
		    if(temp!=NULL)
		    {   if(temp->link!=NULL)
			    ptr->link=temp->link;
			    else
			    ptr->link=NULL;
		        cout<<"The number  being deleted is "<<temp->data<<endl;
		    	delete temp;
			}
			else
			cout<<"Number not found ..."<<endl;			
		}
		void delbefore(int sval){
			node *temp=head;
			node *ptr=head;
			if(head==NULL){
			cout<<"Deletion not possible ..."<<endl;
			return ; 	
			}
			while(temp!=NULL && temp->link->data!=sval)
			{   ptr=temp;
				temp=temp->link;
			}
		    if(temp!=NULL)
		    {   
		        ptr->link=temp->link;
		        cout<<"The number  being deleted is "<<temp->data<<endl;
		    	delete temp;
			}
			else
			cout<<"Number not found ..."<<endl;			
		}
		void del_first(){
			node *temp=head;
			head=head->link;
			cout<<"The number  being deleted is "<<temp->data<<endl;
			delete temp;
		}
		void del_last()
		{
			node *temp=head;
			node *save=head;
			while(temp->link!=NULL){
				save=temp;
				temp=temp->link;
			}
			cout<<"The number  being deleted is "<<temp->data<<endl;
			save->link=NULL;
			delete temp;
		}
		void display(){
			node *temp=head;
			while(temp!=NULL){
				cout<<"The value is "<<temp->data<<endl;
			temp=temp->link;
			}
			cout<<endl;
		}
};

int main()
{
	Singlylinkedlist sl;
	
	sl.addfront(23);
	sl.addfront(33);
	sl.addfront(43);
	sl.addfront(53);
    
    sl.display();
    
    sl.addlast(13);
    sl.addbefore(42,43);
    sl.addafter(44,43);
    
    sl.display();
    
    sl.del_first();
    sl.delafter(33);
    sl.delbefore(43);
    sl.del_last();
    
    sl.display();
	
	return 0;
}
