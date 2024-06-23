#include<iostream>
using namespace std;

const int max=7;
class Quicksort{
	int arr[max];
	public:
		Quicksort(){
		arr={45,65,34,52,76,98,12};
		}
		void display(){
			for(int i=0;i<max;i++)
			{
				cout<<"The value at "<<i<<" is "<<arr[i]<<endl;
			}
		}
		int partition(int left,int right,int pivot){
			int lb=left-1;
			int ub=right;
			while(arr[++lb]<pivot);
			while(ub>0&&ar[--ub]>pivot);
			
			if(lb>=ub)
			break;
			else
			swap(lb,ub);
		}
};

int main(){
	
	
	
	
	return 0;
}
