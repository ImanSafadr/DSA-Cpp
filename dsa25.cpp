#include<iostream>
using namespace std;
const int Size=10;

class Stack{
	int top;
	char element[Size];
	public:
		Stack(){
			top=-1;
		}
    void push(char x){ 
    	if(top==Size)
		cout<<"The stack is full"<<endl;
		else
		top++;
		element[top]=x;
	}
	char pop(){
		if(top==-1)
		cout<<"The stack is empty"<<endl;
		else
		return element[top--];
	}
	char Top(){
		if(top==-1)
		cout<<"The stack is empty"<<endl;
		else
		return element[top];
	}
	bool empty(){
		if(top==-1)
		return true;
		else
		return false;
	}
};
int main()
{
	Stack s;
	s.push('f');
	s.push('i');
	s.push('g');
	s.push('h');
	s.push('t');
	
	cout<<s.pop();
	cout<<s.pop();
	cout<<s.pop();
	cout<<s.pop();
	cout<<s.pop();
	
	return 0;
}
