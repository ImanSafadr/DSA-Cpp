#include<iostream>
using namespace std;
int main(){
	int size=20;
	int arr[size],n,pos,val;
	cout<<"The number of elements is ";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Enter the value of the element ";
		cin>>arr[i];
	}
	cout<<"Enter the position of the new element ";
	cin>>pos;
	cout<<"Enter the value of new element ";
	cin>>val;
	for(int i=0;i<size;i++){
		if(i>n-1)
		n++;
		if(i==pos-1)
		{arr[i]=val;
		break;}
		}
	for(int i=0;i<n;i++){
	cout<<"the element is "<<arr[i]<<endl;	
	}
	return 0;
}
