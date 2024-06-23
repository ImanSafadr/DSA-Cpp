#include<iostream>

using namespace std;
const int Size=5;

class Stack{
	int top;
	int element[Size];
	public:
		Stack(){
			top=-1;
		}
    void push(int x){ 
    	if(top==Size)
		cout<<"The stack is full"<<endl;
		else
		top++;
		element[top]=x;
	}
	int pop(){
		if(top==-1)
		cout<<"The stack is empty"<<endl;
		else
		return element[top--];
	}
	int Top(){
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
	int val;
	
	for(int i=0;i<Size;i++)
	{
		cout<<"Enter value ";
		cin>>val;
		s.push(val);
	}
	int min=s.Top();
		for(int i=0;i<Size;i++)
	{
		int currtop=s.pop();
		if(min>currtop)
		min=currtop;
}
cout<<"min value is "<<min<<endl;
	return 0;
}
