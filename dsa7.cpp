//Evaluating Postfix expression

#include <iostream>

#include <string>

#include <math.h>

using namespace std;

#define LIM 100

int calc (int, int , char);

class stack

{

private:

	int top;

	int items[LIM];

public:

	stack()

	{

		top = -1;

	}

	void push(int v)

	{

		if (top == LIM-1)

		{

			cout << "Overflow";

			exit(1);

		}

		top++;

		items[top] = v;

	}

	bool empty()

	{

		if (top == -1)

			return true;

		else

			return false;

	}

	int pop()

	{

		if (top == -1)

		{

		cout << "Unerflow";

			exit(1);

		}

		return (items[top--]);

	}

};

int main()

{
	string exp, s1 ;
     stack s;
	double op1, op2, r;

	cout << "Enter string";

	cin >>exp;

	for (int i=0; i< exp.length(); i++)

	{

		char symb= exp[i];

		if (symb >='0' && symb <= '9')

			s.push((double)(symb - '0'));

		else

		{

			op2 = s.pop();

			op1 = s.pop();

			r = calc(op1, op2, symb);

			s.push(r);

		}

	}

	cout << s1;"Result is "<< s.pop();	

}

int calc (int op1, int op2, char ch)

{

	switch (ch)

	{

	case '+': return op1+op2; break;

	case '-': return op1-op2; break;

	case '*': return op1*op2; break;

	case '/': return op1/op2; break;

	case '$': return pow(op1,op2); break;

	}
return 0;
}

//Practice Questions
//
//Write a program to evaluation of Prefix expression.
//
//Read a string form user to check whether it is palindrome or not.
//
//
//
//
//
//?
//
//Stack Primitive Operations
//
//
//Converting Infix expression to postfix expression
//
//#include <string>
//
//#include <math.h>
//
//Using namespace std;
//
//
//
//#define LIM 100
//
//Bool prcd (char, char);
//
//Class stack
//
//{
//
//Private:
//
//	Int top;
//
//	Char items[LIM];
//
//Public:
//
//	Stack()
//
//	{
//
//		Top = -1;
//
//	}
//
//	Void push(char v)
//
//	{
//
//		If (top == LIM-1)
//
//		{
//
//			Cout << "Overflow";
//
//			Exit(1);
//
//		}
//
//		Top++;
//
//		Items[top] = v;
//
//	}
//
//	Char pop()
//
//	{
//
//		If (empty())
//
//		{
//
//			Cout << "Unerflow";
//
//			Exit(1);
//
//		}
//
//		Return (items[top--]);
//
//	}
//
//	Char stacktop()
//
//	{
//
//		Return (items[top]);
//
//	}
//
//	Bool empty()
//
//	{
//
//		If (top == -1)
//
//			Return true;
//
//		Else
//
//			Return false;
//
//	}
//
//};
//
//Void main()
//
//{
//
//	Stack s;
//
//	Int j=0;
//
//	String exp, post ;
//
//	For (int i=0; i< exp.length(); i++)
//
//	{
//
//		Char symb= exp[i];
//
//		If (symb >='A' && symb <= 'Z')
//
//			Post.append(1,symb);
//
//		Else
//
//		{
//
//			While (!s.empty() && prcd(s.stacktop(), symb))
//
//			{
//
//				Char topsymb = s.pop();
//
//				Post.append(1,topsymb);
//
//			}
//
//			If (s.empty() || symb != ')')
//
//				s.push(symb);
//
//			else
//
//				s.pop();
//
//		}
//
//		
//
//	}
//
//	While (!s.empty())
//
//	{
//
//		Char topsymb = s.pop();
//
//		Post.append(1,topsymb);
//
//	}
//
//		
//
//	Cout << "Result is "<<  post;	
//
//}
//
//
//
//Bool prcd (char top, char symb)
//
//{
//
//	If (top == '(' || symb  == '(')
//
//		Return false;
//
//	If (symb == ')')
//
//		Return true;
//
//	If (symb == '$')
//
//		Return false;
//
//	If (top == '$')
//
//		Return true;
//
//	If ((top== '*' ||top == '/') && ( symb== '*' || symb == '/'))
//
//		Return true;
//
//	If (symb == '+' ||symb == '-') 
//
//		Return true;
//
//	Else
//
//     	Return false;
//
//}

//Exercise
//
//Write a program to convert an infix expression to prefix 



