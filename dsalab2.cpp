#include<iostream>
using namespace std;

struct node{
	int data;
	node *right;
	node* down;
};
class SinglyLinkedList{
	private:
		node *rhead;
		node *dhead;
		public:
			SinglyLinkedList(){
				rhead=NULL;
				dhead=NULL;
			}
			void addright(int val)
			{ 	node *ichi=new node;
				ichi->data=val;
				ichi->right=rhead;
				rhead=ichi;
			}
				void adddown(int val)
			{ 	node *ichi=new node;
				ichi->data=val;
				ichi->down=dhead;
				dhead=ichi;
			}
			void flattenr(SinglyLinkedList sl1){
				node *temp=rhead;
				while(temp!=NULL){
				cout<<"The value added is "<<temp->data<<endl;
			    sl1.addright(temp->data);
			    temp=temp->right;
			}
			}
			void flattend(SinglyLinkedList sl1){
				node *temp=dhead;
				while(temp!=NULL){
				cout<<"The value added is "<<temp->data<<endl;
			    sl1.addright(temp->data);
			    temp=temp->down;
			}
			}
			
	
		void displayright(){
			node *temp=rhead;
			while(temp!=NULL){
				cout<<"The value is "<<temp->data<<endl;
			temp=temp->right;
			}
			cout<<endl;
		}
		void displaydown(){
			node *temp=dhead;
			while(temp!=NULL){
				cout<<"The value is "<<temp->data<<endl;
			temp=temp->down;
			}
			cout<<endl;
		}
		void display(){
			node *temp=rhead;
			while(temp!=NULL){
				cout<<"The value is "<<temp->data<<endl;
			temp=temp->right;
			}
			cout<<endl;
		}
};

int main()
{
	SinglyLinkedList sl, sl1;
	
    sl.addright(1);
    sl.addright(2);
    sl.addright(3);
    sl.addright(4);
    sl.addright(5);
    
    sl.adddown(6);
    sl.adddown(7);
    sl.adddown(8);
    sl.adddown(9);
    sl.adddown(10);
    
    sl.displayright();
    
    sl.displaydown();
    
    sl.flattend(sl1);
    sl.flattenr(sl1);
    
    sl1.display();
	return 0;
}
