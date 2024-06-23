#include<iostream>
using namespace std;
bool precedence (char,char);
const int Max=15;
class Stack
{
private:
   char items[Max];
   int top;
   
public:
    Stack():top(-1){}

bool isEmpty()
 {
   if (top==-1)
   return true;
   else
   return false;
 }
 
char stacktop()
 {
 return items[top];
 }
 
 void push(char ch)
 {
 if(top==Max-1)
 {
   cout << "over flow \n"; 
   exit(1);
 }
   items[++top]=ch;
 }
 char pop()
 {
 if(top==-1)
 {
   cout << "under flow \n"; 
   exit(1);
 }
 return items[top--];
 }
 
};
int main()
{
Stack stk;
string infix,postfix;
int i; 
  cout << "Enter infix string :";  
  cin>>infix; 
for(i=0;i<infix.length();i++)  
{
  char symbol=infix[i];
 if(symbol>='A'&& symbol<='Z') 
  postfix.append(1, symbol);
  
 else
  {
 while(!stk.isEmpty()&& precedence(stk.stacktop(), symbol) )
 {
 char topsymbol =stk.pop();
 postfix.append(1,topsymbol);
 }
 if(stk.isEmpty()|| symbol!=')')
 stk.push(symbol);
 else
 stk.pop();
  }  
}

while (!stk.isEmpty())
{
char topsymbol=stk.pop();
postfix.append(1, topsymbol);
}

  cout << "Post fix string="<<postfix<<endl; 
  
    
    return 0;
}

bool precedence(char top,char symbol)
{

if(top=='(' || symbol=='(')
return false;
if(symbol==')')
return true ;
if (symbol=='$')
return false;
if(top=='$')
return true;

if(top=='*'||top=='/'&& symbol=='*'||symbol=='/')
return true ;
if(symbol=='+'|| symbol=='-')
return true ;
else 
return false ;

}
