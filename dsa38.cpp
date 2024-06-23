#include<iostream>
using namespace std;

struct node{
	int data;
	node *link;
};

class linklist{
	node *head;
	public:
		linklist(){
			head=NULL;
		}
    bool empty(){
    	if(head==NULL)
    	return true;
    	else 
    	return false;
	}		
	
	void push(int val)
	{
		node *element= new node;
		element->data=val;
		element->link=head;
		head=element;	
	}
	void display(){
		node *temp = head;
		while(temp!=NULL){
			cout<<temp->data<<endl;
			temp=temp->link;
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
		head=head->link;
		delete temp;
		return data;
	}
};


int main()
{
	linklist l;
	
	
	l.push(43);
	l.push(83);
	l.push(73);
	l.push(63);
	l.push(53);
	

	
	l.display();
	
	cout<<l.empty()<<endl;
	
	cout<<l.pop()<<endl;
	cout<<l.pop()<<endl;
	cout<<l.pop()<<endl;
	cout<<l.pop()<<endl;
	cout<<l.pop()<<endl;
	cout<<l.pop()<<endl;
	
	
	
	return 0;
}
