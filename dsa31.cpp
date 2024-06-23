#include<iostream>
using namespace std;

void insert(int arr[],int size){
	int key,i,j;
	for( i=1;i<size;i++)
	{
		key=arr[i];
		for(j=i-1;j>=0 && key<arr[j];j--)
		{
			arr[j+1]=arr[j];
		}
		arr[j+1]=key;
	}
}

int main()
{ 
    int size=5;
	int arr[size]={3,5,2,1,4};
	for(int i=0;i<size;i++)
	{
		cout<<"The value at "<<i<<" is : "<<arr[i]<<endl;
	}
	
	insert(arr,size);
	cout<<"After sorting"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<"The value at "<<i<<" is : "<<arr[i]<<endl;
	}
	return 0;
}
