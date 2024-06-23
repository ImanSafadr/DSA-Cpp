#include<iostream>
using namespace std;

int partition(int arr[], int l,int h)
{
	int pivot=arr[h];
	int i=l-1;
	for(int j=l;j<h;j++)
	{
		if(pivot>arr[j])
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[h]);
	return  i+1;
}

void quicksort(int arr[],int l, int h)
{
	if(l<h)
	{
	    int piv=partition(arr,l,h);
		
		quicksort(arr,l,piv-1);
		quicksort(arr,piv+1,h);
		
	}
}

int recbin(int arr[],int sno,int l,int h)
{
	int mid=(l+h)/2;
	if(l>h)
	return -1;
	else if (arr[mid]==sno)
	return mid;
	else if(arr[mid]>sno)
	return recbin(arr,sno,l,mid-1);
    else if(arr[mid]<sno)
	return recbin(arr,sno,mid+1,h);
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
	
//	int sno;
//	cout<<"Enter the search number : ";
//	cin>>sno;
//	
//	int res=recbin(arr,sno,l,h);
//	if(res==-1)
//	cout<<"The number was not found"<<endl;
//	else if(res>-1)
//	cout<<"The number "<<sno<<" was found at index "<<res<<endl;
	return 0;
}
