#include<iostream>
using namespace std;

const int size=20;
class Stack{
	int arr[size];
	int top;
	int index;
	public:
		Stack(){
		    top=-1;
			for(int i=0;i<size;i++){
				arr[i]=0;
			}
		}
	void Push(int x){
		if(top==size-1){
			cout<<"Array already full"<<endl;
		exit(1);
		}
		top++;
		arr[top]=x;
	}
	void insert(){
		cout<<"Enter the index";
		cin>>index;
		for(int i=top;i>=index;i--){
			arr[i+1]=arr[i];
		}
		cout<<"Enter the value ";
		cin>>arr[index];
		top++;

	}
	void Pop()
 {
 if(top==-1)
 {
   cout << "under flow \n"; 
   exit(1);
 }
 top--;
 }
 void dalete()
 {
 		cout<<"Enter the index";
		cin>>index;
		for(int i=index;i<=top-1;i++){
			arr[i]=arr[i+1];
		}
 top--;
 }
	int Top(){
			if(top==-1){
			cout<<"Array is empty"<<endl;
		}
		
	return top;	
	}
	bool empty(){
		if(top==-1)
		return true;
		else
		return false
		;
	}
	void show(){
		for(int i=0;i<=top;i++){
			cout<<"The value is "<<arr[i]<<endl;
		}
	}
};
int main(){
	
	Stack s;
	cout<<s.Top()<<endl;
	
	s.Push(11);
	s.Push(12);
	s.Push(13);
	s.Push(14);
	s.Push(15);
	s.Push(16);
	
	s.insert();
	
	s.show();
	cout<<s.Top();
	cout<<endl;
	s.dalete();
	
	s.show();
	cout<<s.Top();
	return 0;
}
