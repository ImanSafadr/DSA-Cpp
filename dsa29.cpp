#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>

using namespace std;
 
const int size=10;

class Stack{
	char arr[size];
	public:
	int top;
	    Stack()
		{
			top=-1;
		}
		void push(char c)
		{
			if(top==size){
				cout<<"Stack already full....."<<endl;
				return;
			}
			else{
				top++;
				arr[top]=c;
			}
		}
		void pop()
		{
			if(top==-1)
			cout<<"Stack is empty..."<<endl;
			else
			top--;
		}
		char Top()
		{
			if(top==-1)
			cout<<"Stack is empty..."<<endl;
			else
			return arr[top];
		}
		bool empty()
		{
			if(top==-1)
			return 1;
			else
			return 0;
		}
}; 
	int prec(char c)
	{
		if(c=='^')
		return 3;
        else if(c=='*'||c=='/')
		return 2;
		else if(c=='+'||c=='-')
		return 1;
		else
		return -1;
	}
	string pretopos(string s)
	{
		Stack stk;
		string res;
		for(int i=0;i<s.length();i++)
		{
			char c=s[i];
			if(isalnum(c))
			res+=c;
			else if(c=='(')
			stk.push(c);
			else if(c==')'){
			while(!stk.empty() && stk.Top()!='(')
			{
				res+=stk.Top();
				stk.pop();	
			}
			if(!stk.empty() && stk.Top()=='(')
			stk.pop();
			
		}
		else
		{
			while(!stk.empty()&&prec(stk.Top())>=prec(c))
			{
				res+=stk.Top();
				stk.pop();
			}
			stk.push(c);
		}
		}
		while(!stk.empty())
		{
		res+=stk.Top();
		stk.pop();
	}
	return res;
}
bool checkop(char c){
	return (c=='^'||c=='/'||c=='*'||c=='+'||c=='-');
}
float evaluate(string s){
	stack<float> stk;
	float operand1,operand2;
	for(int i=0;i<s.length();i++)
	{
		char c=s[i];
		if(isdigit(c))
		stk.push(c-'0');
		else if(checkop(c)){
			if(stk.size()<2)
			{
			cout<<"The process cannot take place "<<endl;
			return 0;
			}
		operand2=stk.top();
		stk.pop();
		operand1=stk.top();	
		stk.pop();
	
		   switch (c) {
            case '+':
                stk.push(operand1 + operand2);
                break;
            case '-':
                stk.push(operand1 - operand2);
                break;
            case '*':
                stk.push(operand1 * operand2);
                break;
            case '/':
                stk.push(operand1 / operand2);
                break;
            case '^':
                stk.push(pow(operand1, operand2));
                break;
            }

		}
		else
		{cout<<"Invalid ... "<<endl;
		return 0;
		}		
}
if(stk.size()==1)
return stk.top();
else
{cout<<"Invalid............... "<<endl;
return 0;
}
}
int main()
{
    string s,result;
    cout<<"Enter the string : ";
    cin>>s;
    
     result=pretopos(s);
    cout<<"The result is = "<<result<<endl;
	
    cout<<"The result is = "<<evaluate(result)<<endl;
	return 0;
}


