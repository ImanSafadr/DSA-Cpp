#include<iostream>
using namespace std;

int partition(int arr[],int l,int h)
{
	int piv=arr[h];
	int i=l-1;
	for(int j=l;j<h;j++)
	{
		if(piv>arr[j])
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[h]);
	return i+1;
}

void quicksort(int arr[],int l, int h)
{
	if(l<h)
	{
		int pivot=partition(arr,l,h);
		
		quicksort(arr,l,pivot-1);
		quicksort(arr,pivot+1,h);
	}
}

int main()
{
	int size=5;
	int arr[size]={3,5,2,1,4};
	int l=0,h=size-1;
	
	for(int i=0;i<size;i++)
	{
		cout<<"The value at "<<i<<" is : "<<arr[i]<<endl;
	}
	
	quicksort(arr,l,h);
	
	cout<<"After sorting"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<"The value at "<<i<<" is : "<<arr[i]<<endl;
	}
	return 0;
}
