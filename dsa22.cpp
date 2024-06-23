#include<iostream>
using namespace std;

int recbin(int a[],int sno,int low,int high){
	if(low>high)
	{return -1;
	}
	int mid=(low+high)/2;
	 if(a[mid]==sno)
	{return mid;
	}
	 if(sno>a[mid])
	{return recbin( a, sno, mid+1, high);
	}
	else if(sno<a[mid])
	return recbin( a, sno, low, mid-1);
}

int main(){
	
	int low,high,snum;
	 int size=5;
	 int arr[size];
	 
	 for(int i=0;i<size;i++)
	 {
	 	cout<<"Enter the value ";
	 	cin>>arr[i];
	 }
	 cout<<"Enter the low value ";
	 	cin>>low;
	cout<<"Enter the value high";
	 	cin>>high;
	 	cout<<"Enter the search number value ";
	 	cin>>snum;
	 int result= recbin(arr,snum,low,high);
	
	if(result==-1)
	cout<<"The number was not found"<<endl;
	else if(result>-1)
	cout<<"The number "<<snum<<" wa found at index "<<result<<endl;
	
	return 0;
}
