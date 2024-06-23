#include<iostream>
using namespace std;

const int size=5;

class Qsort{
	public:
		int arr[size];
		int l ,r;
		Qsort(){}
		 
		 void input(){
		 		for(int i=0;i<size;i++)
			{
				cout<<"Enter the value at "<<i<<": ";
				cin>>arr[i];
			}
			cout<<"Enter left: ";
			cin>>l;
			cout<<"Enter right: ";
			cin>>r;
		 }
		 
		 void Swap(int arr[],int a,int b){
			int temp=arr[a];
			arr[a]=arr[b];
			arr[b]=temp;
		}
		
		int partition(int arr[],int l,int r){
		int pv=arr[r];
		int i=l-1;
		for(int j=l;j<r;j++)
		{
			if(arr[j]<pv)
			{
				i++;
				Swap(arr,i,j);
			}
			}
				Swap(arr,i+1,r);
			return i+1;	
	}
		void Quicksort(int arr[],int l,int r)
		{
		   
		   if(l<r){
		   	
		   	int pv=partition(arr,l,r); 
		   	 
		   	Quicksort(arr,l,pv-1);
		   	Quicksort(arr,pv+1,r);
		   	
		   }
		}
		void show()
		{
			for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
		}
};

int main(){
	
	Qsort s;
	s.input();
	s.Quicksort(s.arr,s.l,s.r);
	
    s.show();
	
	return 0;
}
