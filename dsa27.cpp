#include<iostream>

using namespace std;
const int Size=10;

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
	void  remdupl(){
    int n=-1;
    cout<<n<<endl;
	int arr[Size];
	
	while(!empty())
    {   
    
    	n++;
		arr[n]=pop();
		cout<<arr[n]<<"  ";
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(arr[i]==arr[j])
			arr[j]=-1;
		}
	}
	for(int i=n;i>=0;i--)
	{   
	    if(arr[i]!=-1)
		{
			push(arr[i]);
			
		}
	}
	}
};
int main()
{
    Stack s;
    s.push(34);
    s.push(24);
    s.push(14);
    s.push(34);
    s.push(24);
    s.push(34);
    s.push(94);
    s.push(84);
    s.push(94);
    
	    cout<<"Before removal "<<endl;
        cout<<"The size is "<<s.top+1<<endl;
        
	cout<<endl;
    s.remdupl();
    
	    cout<<"After removal "<<endl;
        cout<<"The size is "<<s.top+1<<endl;
    while(!s.empty())
    {
    	cout<<s.pop()<<"  ";
	}
	
	return 0;
}
