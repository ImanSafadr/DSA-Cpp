#include<iostream>
using namespace std;

const int size=10;

class Sort{
	public:
	int arr[size];
	int l,r;
		Sort(){}
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
			int pivot=arr[r];
			int i=l-1;
			for (int j=l;j<r;j++){
				if (arr[j]<pivot)
				{
					i++;
					Swap(arr,i,j);
				}
			}
			Swap(arr,i+1,r);
			return i+1;
		}
		
		void Quicksort(int arr[],int l,int r){
			if(l<r){
				int pv=partition(arr,l,r);
				
				Quicksort(arr,l,pv-1);
				Quicksort(arr,pv+1,r);
			}
		}
};

int main()
{
	Sort s;
	s.input();
	s.Quicksort(s.arr,s.l,s.r);
	
	for(int i=0;i<size;i++)
	{
		cout<<s.arr[i]<<" ";
	}
	return 0;
}
