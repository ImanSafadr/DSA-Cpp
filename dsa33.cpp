#include<iostream>
using namespace std;

void merge(int arr[], int l,int mid, int h)
{
	int n1=mid-l+1;
	int n2=h-mid;
	
	int a[n1];
	int b[n2];
	
	for(int i=0;i<n1;i++)
	{
		a[i]=arr[l+i];
	}
	for(int i=0;i<n2;i++)
	{
		b[i]=arr[mid+1+i];
	}
	
	int i=0;
	int j=0;
	int k=l;
	while(i<n1&&j<n2)
	{
		if(a[i]<b[j])
		{
			arr[k]=a[i];
			i++;
			k++;
		}
		if(a[i]>b[j])
		{
			arr[k]=b[j];
			j++;
			k++;
		}
	}
	while(i<n1)
	{
		arr[k]=a[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=b[j];
		j++;
		k++;
	}
}

void mergesort(int arr[],int l, int h)
{
	if(l<h)
	{
	    int mid=(l+h)/2;
		
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,h);
		
		merge(arr,l,mid,h);
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
	
	mergesort(arr,l,h);
	
	cout<<"After sorting"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<"The value at "<<i<<" is : "<<arr[i]<<endl;
	}
	
	int sno;
	cout<<"Enter the search number : ";
	cin>>sno;
	
	int res=recbin(arr,sno,l,h);
	if(res==-1)
	cout<<"The number was not found"<<endl;
	else if(res>-1)
	cout<<"The number "<<sno<<" was found at index "<<res<<endl;
	return 0;
}
