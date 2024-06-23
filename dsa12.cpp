#include<iostream>
using namespace std;

void tower(int x, char src,char aux, char des)
{
	if(x>1){
		tower(x-1, src, des, aux);
		tower(1, src, aux,  des);
		tower(x-1, aux, src,  des);
	}
	else
	cout<<src<<"-->"<<des<<endl;
}

int main()
{
 int no;
 
 cout<<"Enter the number ";
 cin>>no;
 
 tower(3,'A','B','C');
	
	
	return 0;
	}
