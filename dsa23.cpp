#include<iostream>
using namespace std;

void insertion(int arr[],int n)
{
	int key,i,j;
	for(i=1;i<n;i++)
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
	 int arr[size];
	 
	 for(int i=0;i<size;i++)
	 {
	 	cout<<"Enter the value ";
	 	cin>>arr[i];
	 }
	insertion(arr,size);
	
	for(int i=0;i<size;i++)
	 {
	 	cout<<"Enter the value is "<<arr[i]<<endl;
}
	return 0;
}
