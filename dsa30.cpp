#include<iostream>
using namespace std;

void select(int arr[],int size){
	int loc;
	for(int i=0;i<size;i++)
	{
		loc=i;
		for(int j=i+1;j<size;j++)
		{
			if(arr[j]<arr[loc])
			loc=j;
		}
		if(loc!=i)
		{
			swap(arr[loc],arr[i]);
		}
	}
}

int main()
{ 
    int size=5;
	int arr[size]={3,5,2,1,4};
	
	select(arr,size);
	
	for(int i=0;i<size;i++)
	{
		cout<<"The value at "<<i<<" is : "<<arr[i]<<endl;
	}
	return 0;
}
