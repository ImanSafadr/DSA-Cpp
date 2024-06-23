#include<iostream>

using namespace std;
const int Size=5;

class Stack{
	int element[Size];
	public:
	int top;
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
	int arr[Size];
	for(int i=0;i<Size;i++)
	{
		cout<<"Enter value ";
		cin>>val;
		s.push(val);
	}
     int middle=s.top/2;
		for(int i=0;i<Size;i++)
	{
	arr[i]=s.pop();
}
cout<<"The middle value is "<<arr[middle]<<endl;
	return 0;
}
