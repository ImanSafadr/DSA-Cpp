#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<cctype>
#include<stack>

using namespace std;

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
string inftopos(string s)
{
	stack<char> stk;
	string res;
	
	for(int i=0;i<s.length();i++)
	{
		if(isalnum(s[i]))
		res+=s[i];
		else if(s[i]=='(')
		stk.push(s[i]);
		else if(s[i]==')')
		{
			while(!stk.empty()&&stk.top()!='(')
			{
				res+=stk.top();
				stk.pop();
			}
			if(!stk.empty()&&stk.top()=='(')
			stk.pop();
		}
		else 
		{
		while(!stk.empty()&&prec(stk.top())>=prec(s[i]))
			{res+=stk.top();
			stk.pop();
		}
		stk.push(s[i]);
		}
	}
	while(!stk.empty()){
			res+=stk.top();
	stk.pop();
	}
	return res;
}

bool isoperator(char c)
{return (c=='^'||c=='/'||c=='*'||c=='+'||c=='-');
}

float evalpos(string s)
{
	stack<float> stk;
	float operand1,operand2;
	for(int i=0;i<s.length();i++)
	{
		char c=s[i];
		if(isdigit(c))
		{stk.push(c-'0');
		}
		else if(isoperator(c))
		{
			if(stk.size()<2)
			{cout<<"cannot perform the operation"<<endl;
			return 0;
			}
			operand2=stk.top();
			stk.pop();
			operand1=stk.top();
			stk.pop();
			switch (c)
			{
				case '+':
					stk.push(operand1+operand2);
					break;
				case '-':
					stk.push(operand1-operand2);
					break;
				case '*':
					stk.push(operand1*operand2);
					break;
				case '^':
					stk.push(pow(operand1,operand2));
					break;
				case '/':
					stk.push(operand1/operand2);
					break;				
			}
		}
		else
		{
			cout<<"invalid expression"<<endl;
			return 0;
		}
	}
	if(stk.size()==1)
	return stk.top();
	else
	{
		cout<<"invalid expression"<<endl;
		return 0;
	}
}

int main()
{
	string s1;
	s1=inftopos("4+5-6*(7/8)+2");
	
	cout<<"The postfix expresion is="<<s1<<endl;
	
	cout<<"The result is: "<<evalpos(s1)<<endl;
	return 0;
}
