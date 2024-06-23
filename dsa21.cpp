#include<iostream>
using namespace std;

const int size=5;

class Msort{
	public:
		int arr[size];
		int l ,r;
		Msort(){}
		 
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
		void merge(int arr[],int l,int mid,int r){
			int s1=mid-l+1;
			int s2=r-mid;
			
			int a[s1];
			int b[s2];
			for(int i=0;i<s1;i++)
			{
				a[i]=arr[l+i];
			}
            for(int i=0;i<s2;i++)
			{
				b[i]=arr[mid+i+1];
			}
			int i=0;
			int j=0;
			int k=l;
			while(i<s1&&j<s2)
			{
				if(a[i]<b[j])
				{
					arr[k]=a[i];
					i++;
					k++;
				}
				else
				{
					arr[k]=b[j];
					j++;
					k++;
				}
			}
			while(i<s1){
				arr[k]=a[i];
					i++;
					k++;
			}
			while(j<s2){
				arr[k]=b[j];
					j++;
					k++;
		}
	}
		void Mergesort(int arr[],int l,int r)
		{
			if(l<r){
		    int mid=(l+r)/2;
				
				Mergesort(arr,l,mid); 
				Mergesort(arr,mid+1,r);
				
				merge(arr,l,mid,r);
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
	
	Msort ms1;
	ms1.input();
	ms1.Mergesort(ms1.arr,ms1.l,ms1.r);
	
    ms1.show();
	
	return 0;
}
