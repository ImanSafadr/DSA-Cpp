#include<iostream>
using namespace std;

const int size=20;
class Stack{
	int arr[size];
	int top;
	public:
		Stack(){
			int top=-1;
		}
	void Push(int x){
		if(top==size-1){
			cout<<"Array already full"<<endl;
		}
		top++;
		arr[top]=x;
	}
	char Pop()
 {
 if(top==-1)
 {
   cout << "under flow \n"; 
   exit(1);
 }
 return arr[top--];
 }
	int Top(){
			if(top==-1){
			cout<<"Array is empty"<<endl;
		}
	return arr[top];	
	}
	bool empty(){
		if(top==-1)
		return true;
		else
		return false
		;
	}
}; 
bool precedence(char top, char sym){
	if(top=='('||sym=='(')
	return false;
	if(sym==')')
	return true;
	if(sym=='$')
	return false;
	if(top=='$')
	return true;
	if(top=='*'||top=='/'&& sym=='*'||sym=='/')
	return true;
	if(sym=='+'||sym=='-')
	return true;
	else
	return false;
}

int main(){
	Stack s;
	string  infix ,postfix;
	int i;
	
	cout<<"Enter the infix string ";
	cin>>infix;
	
	for(i=0;i<infix.length();i++)
    {
    	char sym =infix[i];
    	if(sym>='A'&&sym<='Z')
    	postfix.append(1,sym);
    	else
    	{
    	while(!s.empty()&&precedence(s.Top(),sym)){
    		char topsym=s.Pop();
    		postfix.append(1,topsym);
		}
		if(s.empty()||sym!=')')
		s.Push(sym);
		else
		s.Pop();	
	}
	}
	while(!s.empty()){
		
		char topsym=s.Pop();
		postfix.append(1,topsym);
	}
	cout<<"postfix string= "<<postfix<<endl;
	return 0;
}
