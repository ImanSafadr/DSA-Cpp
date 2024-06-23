#include<iostream>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<stack>
#include<string>
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
int prec(char c){
	if (c == '^')
 {
 return 3;
 }
 else if (c == '/' || c == '*')
 {
 return 2;
 }
 else if (c == '-' || c == '+')
 {
 return 1;
 }
 else
 {
 return -1;
}
}
string inftopos(string s){
	string res;
	Stack stk;
	for(int i=0;i<s.length();i++)
	{
		if(isalnum(s[i]))
		res+=s[i];
		else if(s[i]=='(')
		stk.push(s[i]);
		else if(s[i]==')')
		{
		while(!stk.empty() && stk.Top()!='(')
		{res+=stk.pop();}
		if(!stk.empty() )
		stk.pop();
		}
		else{
			while(!stk.empty()&&prec(stk.Top())>=prec(s[i]))
			{res+=stk.pop();
			}
			stk.push(s[i]);
		}
	}
	while(!stk.empty())
	{res+=stk.pop();
	}
	return res;

}

bool checkop(char c){
	return (c=='^'||c=='/'||c=='*'||c=='+'||c=='-');
}
float evalpost(string str)
{
	stack<float> stk;
	float operand1,operand2;
	for(int i=0;i<str.length();i++)
	{
		char c=str[i];
		if(isdigit(c))
		stk.push(c-'0');
	    else if(checkop(c)){
	    	if(stk.size()<2){
	    		cout<<"the process cannot take place ."<<endl;
	    		return 0;
			}
			operand2=stk.top();
			stk.pop();
			cout<<operand2<<endl;
            operand1=stk.top();
			cout<<operand2<<endl;
			stk.pop();
			switch (c){
				case '+':
					stk.push(operand1+operand2);
					break;
				case '-':
					stk.push(operand1-operand2);
					break;
				case '*':
					stk.push(operand1*operand2);
					break;
				case '/':
					stk.push(operand1/operand2);
					break;
				case '^':
					stk.push(pow(operand1,operand2));
					break;				
			} 
		}
	else{
	cout<<"Invalid expression"<<endl;
	return 0;
}
	}
	if(stk.size()==1)
	return stk.top();
	else
	{cout<<"Invalid expression"<<endl;
	return 0;
	}
}

int main()
{
	string s1;
	s1=inftopos("4+5-6*(7/8)+2");
	
	cout<<s1<<endl;
	
	cout<<"The result is "<<evalpost(s1)<<endl;
	
	
	return 0;
}
