#include<iostream>
using namespace std;

struct node{
	int data;
	node *link;
};
class cqueue{
	node *r;
	public:
		cqueue(){
			r=NULL;
		}
    void enqueue(int val){
    	node *ele= new node;
    	ele->data=val;
    	if(r==NULL){
    		r=ele;
    		r->link=r; // this line is very important. it tell the pointer to point towards itself.
		}
		else
		{
			ele->link=r->link;
			r->link=ele;
			r=ele;
		}
	}
	int dequeue()
	{
		if(r == NULL) {
			cout << "Queue is empty" << endl;
			return -1; // Return an error value or handle this case appropriately
		}
		
		node *temp = r->link;
		int val= temp->data;
		if(r==r->link)
		r=NULL;
		else
		r->link=temp->link;
		
		delete temp;
		return val;
	}
	void display(){
		node *temp=r->link;
		while(temp!=r){
			cout<<"The value is "<<temp->data<<endl;
			temp=temp->link;
		}
			cout<<"The value is "<<temp->data<<endl;
	}
};

int main(){
	cqueue cq;
	cq.enqueue(3);
	cq.enqueue(4);
	cq.enqueue(5);
	cq.enqueue(6);
	
	cq.display();
	
	cout<<cq.dequeue()<<endl;
	cout<<cq.dequeue()<<endl;
	cout<<cq.dequeue()<<endl;
//	cout<<cq.dequeue()<<endl;
	
	cq.display();
	return 0;
}
