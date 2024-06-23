#include<iostream>
using namespace std;

class stack{
	int size=100;
	int arr[size];
	int top;
	public:
		stack(){
			top=-1;
		}
		void input(int val){
			if(top<size-1)
			arr[++top]=val;
			else 
			cout<<"THe stack is full"<<endl;
		}
		void pop(){
			if(!i)
			
		}
};

int main(){
	orderedArray oa;
	oa.insert(60);
	oa.insert(50);
	oa.insert(40);
	
	oa.display();
	
	return 0;
}
