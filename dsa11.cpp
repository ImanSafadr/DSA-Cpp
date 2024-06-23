#include<iostream>
using namespace std;

int fun(int a,int b){
	int res=1;
	for(int i=0;i<b;i++)
	{ res=res*a;
	}
	return res;
}

int main()
{
	int base,exp;
    
	cin>>base;	
	cin>>exp;
	
	cout<<fun(base,exp);	
	return 0;
}
