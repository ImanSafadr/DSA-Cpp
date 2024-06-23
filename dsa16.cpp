#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <cctype>
#include <cmath>
using namespace std;
int Precedance(char c)
{
 if (c == '^')
 {
 return 4;
 }
 else if (c == '/' || c == '*')
 {
 return 3;
 }
 else if (c == '-' || c == '+')
 {
 return 2;
 }
 else
 {
 return -1;
 }
}
string InfixToPostfix(string s)
{
 stack<char> stk;
 string Result;
 for (int i = 0; i < s.length(); i++)
 {
 if (isalnum(s[i]))
 {
 Result += s[i];
 }
 else if (s[i] == '(')
 {
 stk.push(s[i]);
 }
 else if (s[i] == ')')
 {
 while (!stk.empty() && stk.top() != '(')
 {
 Result += stk.top();
 stk.pop();
 }
 if (!stk.empty() && stk.top() == '(')
 {
 stk.pop(); // Pop the opening parenthesis
 }
 }
 else
 {
 while (!stk.empty() && Precedance(stk.top()) >= Precedance(s[i]) && 
stk.top() != '(')
 {
 Result += stk.top();
 stk.pop();
 }
 stk.push(s[i]);
 }
 }
 while (!stk.empty())
 {
 Result += stk.top();
 stk.pop();
 }
 return Result;
}
bool IsOperator( char c)
{
 return ( c == '+' || c == '-' || c == '^' || c == '/' || c == '*');
}
float EvaluatePostfix(string postfix)
{
 stack<float> stk;
 float Operand1, Operand2;
 for(int i = 0 ; i < postfix.length(); i++)
 {
 char c = postfix[i];
 if(isdigit(c))
 {
 stk.push(c - '0');
 }
 else if(IsOperator(c))
 {
 if(stk.size() < 2)
 {
 cout << "Cannot perform the processing!" << endl;
 return 0;
 }
 Operand2 = stk.top();
 stk.pop();
 Operand1 = stk.top();
 stk.pop();
 switch (c)
 {
 case '+':
 stk.push(Operand1 + Operand2);
 break;
 case '-':
 stk.push(Operand1 - Operand2);
 break;
 case '*':
 stk.push(Operand1 * Operand2);
 break;
 case '/':
 stk.push(Operand1 / Operand2);
 break;
 case '^':
 stk.push(pow(Operand1, Operand2));
 break;
 }
 }
 else
 {
 cout << "Invalid Postfix Expression" << endl;
 return 0;
 }
 }
 if(stk.size() == 1)
 {
 return stk.top();
 }
 else
 {
 cout << "Invalid Postfix Expression " << endl;
 }
}
int main()
{
 cout << "Infix to Postfix conversion: " ;
 string Postfix = InfixToPostfix("3+4*2/(1-5)^2");
 cout << Postfix << endl;
 float Answer = EvaluatePostfix(Postfix);
 cout << "The Final Answer after the Solving of Postfix Expression: " << Answer 
<< endl;
 return 0;
}
