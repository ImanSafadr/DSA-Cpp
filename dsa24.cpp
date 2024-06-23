#include<iostream>
using namespace std;

void select(int arr[],int n)
{
	int loc;
	for(int i=0;i<n-1;i++)
	{
		loc=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[loc]>arr[j])
			loc=j;
		}
		if(loc!=i)
		{
			swap(arr[i],arr[loc]);
		}
	}
}
int main()
{
	int size=5;
	 int arr[size];
	 
	 for(int i=0;i<size;i++)
	 {
	 	cout<<"Enter the value ";
	 	cin>>arr[i];
	 }
	select(arr,size);
	
	for(int i=0;i<size;i++)
	 {
	 	cout<<"Enter the value is "<<arr[i]<<endl;
}
	return 0;
}
