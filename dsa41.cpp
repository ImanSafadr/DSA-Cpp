#include<iostream>
using namespace std;

struct node{
    int priority;
	int data;
	node *link;
};
class pqueue{
	node *front;
	public:
		pqueue(){
			front=NULL;
		}
		void addval(int val, int pri){
			node *ele= new node;
			ele->data=val;
			ele->priority=pri;
			if(front==NULL || pri<=front->priority){
				ele->link=front;
				front=ele;
			}
			else{
				node *pred=front;
				while(pred->link!=NULL && pred->link->priority<=pri){
					pred=pred->link;
				}
				ele->link=pred->link;
				pred->link=ele;
			}
		}
		int remove(){
			node *temp=front;
			int val=temp->data;
			front=front->link;
			delete temp;
			return val;
		}
		void display(){
			node *temp=front;
			while(temp!=NULL){
				cout<<temp->data<<endl;
				temp=temp->link;
			}
		}
};

int main(){
	
	pqueue pq;
	
	pq.addval(2,44);
	pq.addval(3,33);
	pq.addval(4,22);
	pq.addval(5,55);
	
	pq.display();
	
	cout<<endl;
	cout<<pq.remove()<<endl;
	cout<<pq.remove()<<endl;
	cout<<pq.remove()<<endl;
	
	return 0;
}
