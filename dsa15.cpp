#include<iostream>
using namespace std;

const int size=20;
class Stack{
	private:
	char elements[size];
    int top;
	public:
	Stack(){
	top=-1;
	}
	void push(char c){
		if(top>=size)
		cout<<"The stack is full"<<endl;
		else
		top++;
		elements[top]=c;
	}
	char pop(){
		if(top==-1)
		cout<<"The stack is empty"<<endl;
		else
		return elements[top--];
	}
	char Top(){
		if(top==-1)
		cout<<"The stack is empty"<<endl;
		else
		return elements[top];
	}	
	bool empty(){
		if (top==-1)
		return true;
		else
		return false;
	}
};
int prec(char ch){
	if(ch=='^')
	return 3;
	else if(ch=='/'||ch=='*')
	return 2;
	else if(ch=='+'||ch=='-')
	return 1;
	else
	return -1;
}
string evaluate(string s){
	Stack stk;
   string res;
   cout<<"Enter the expression ";
   cin>>s;
   for(int i=0;i<s.length();i++){
   	if(s[i]>='A'&&s[i]<='Z'||s[i]>='a'&&s[i]<='z')
   	res+=s[i];
   	else if(s[i]=='(')
   	stk.push(s[i]);
   	else if(s[i]==')')
   	{
   		while(!stk.empty()&&stk.Top()!='(')
        {res+=stk.Top();
		stk.pop() ;  	}	
	   if(!stk.empty())
	   stk.pop();
	   }
	   else{
	   	while(!stk.empty()&& prec(stk.Top())>=prec(s[i]))
	    {
	    	res+=stk.Top();
		stk.pop() ;
		}
		stk.push(s[i]);
		}
   }	
	while(!stk.empty())
	{
		res+=stk.Top();
		stk.pop() ;
	}
	return res;
}
int main(){
   
   string s;
	
	
	cout<<"the result = "<<evaluate(s)<<endl;
	
	return 0;
}
