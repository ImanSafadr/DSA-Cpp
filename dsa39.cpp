#include<iostream>
using namespace std;

struct node{
	int data;
	node *link;
};
class queue{
	node *f;
	node *r;
	public:
		queue(){
			f=r=NULL;
		}
	void enqueue(int val){
		node *element= new node;
		if(element==NULL)
		{
			cout<<"The queue is full"<<endl;
		}
        else{
        	element->data=val;
        	element->link=NULL;
        	if(f==NULL)
        	f=r=element;
        	else{
        	r->link=element;
        	r=element;
        }
		}
	}
	void display(){
		node *temp=f;
		while(temp!=NULL){
			cout<<temp->data<<endl;
			temp=temp->link;
		}
//		temp=temp->link;
//		delete temp;
//		return data;
	}	
	int dequeue(){
		node *temp=f;
		int data=temp->data;
		f=f->link;
		delete temp;
		return data;
	}	
	
};

int main()
{
	queue q;
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(7);
	
	q.display();
	
	
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	
	q.display();
	return 0;
}
