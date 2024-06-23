#include<iostream>
using namespace std;

const int MAX= 15;
class orderedArray{
	int arr[MAX];
	int count;
public:

orderdArray(){
    count=0;
}	

int size(){
	return count;
}

void insersion(int val)
{
	
	int i,j;
	for(i=0;i<4;i++)
	{
	if(arr[i]>val)
	break;

	for(j=count;j>i;j--)
	arr[j]=arr[j+1];

	arr[i]=val;
	count++;
}
}
void show(){
	for(int i=0;i<count;i++){
		cout<<arr[i];
		}
	cout<<count;
}
};

int main(){
	
	orderedArray oa;
	oa.insersion(8);
    oa.show();
	return 0;
}
