//Program of the insert of an element in an array at a specific position

//#include <iostream>
//using namespace std;
//int main()
//{
//   int  position, c, n, value;
//   cout<<"Enter number of elements in array\n"<<endl;
//   cin>>n;
//   int array[100];
//   cout<<"Enter elements\n"<<endl;
//   for (int i = 0; i < n; i++)
//   {
//   cin>>array[i];
//    }
//   cout<<"Enter the location where you wish to insert an element\n"<<endl;
//   cin>>position;
//   cout<<"Enter the value to insert\n"<<endl;
//   cin>>value;
//   for (int i = n - 1; i >= position - 1; i--)
//   {
//  array[i+1] = array[i];
//    }
//	array[position-1] = value;
//    cout<<"Resultant array is\n"<<endl;
//   for (int i = 0; i <= n; i++)
//   {
//      cout<<array[i]<<endl; 
//         }
//   return 0;
//}


// Program to insert an element into the beginning of array
//
//
//#include <iostream>
//#include <stdio.h>
// 
//#define MAXIMUM 5
// 
//int main() {
//   int arr[MAXIMUM] = {6, 2, 1, 7};
//   int N = 4;        // number of elements in array
//   int i = 0;        // loop variable
//   int value = 1;    // new data element to be stored in array
// 
//   // print array before insertion
//   printf("Printing array before insertion -\n");
//   
//   for(i = 0; i < N; i++) {
//      printf("arr[%d] = %d \n", i, arr[i]);
//   }
// 
//   // now shift rest of the elements downwards   
//   for(i = N; i >= 0; i--) {
//      arr[i+1] = arr[i];
//   }
// 
//   // add new element at first position
//   arr[0] = value;
// 
//   // increase N to reflect number of elements
//   N++;
// 
//   // print to confirm
//   printf("Printing array after insertion -\n");
//   
//   for(i = 0; i < N; i++) {
//      printf("arr[%d] = %d\n", i, arr[i]);
//   }
//return 0;
//}
//
////Program to insert an element Before the Given Index of an Array
//
//#include <iostream>
//#include <stdio.h>
// 
//#define MAXIMUM 5
//int main() {
//   int arr[MAXIMUM] = {2, 6, 1, 7};
//   
//   int N = 4;        
//// number of elements in array
//   int i = 0;        
//// loop variable
//   int index = 3;    
//// index location before which value will be inserted
//   int value = 9;    
//// new data element to be inserted
// 
//   // print array before insertion
//   printf("Printing array before insertion -\n");
// 
//   for(i = 0; i < N; i++) {
//      printf("arr[%d] = %d \n", i, arr[i]);
//   }
// 
//   // now shift rest of the elements downwards   
//   for(i = N; i >= index + 1; i--) {
//      arr[i + 1] = arr[i];
//   }
// 
//   // add new element at first position
//   arr[index + 1] = value;
// 
//   // increase N to reflect number of elements
//   N++;
// 
//   // print to confirm
//   printf("Printing array after insertion -\n");
// 
//   for(i = 0; i < N; i++) {
//      printf("arr[%d] = %d\n", i, arr[i]);
//   }
//}

////C++ program to find maximum and minimum element in array
//
#include<iostream>
using namespace std;
#define size10
int main()
{
	int arr[10];
	int i,max,min;
	for(i=0;i<10;i++)
	{
	cout<<"enter element in the array ";
		cin>>arr[i];
	}
	max=arr[0];
	min=arr[0];
	for(i=1;i<10;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
		if(arr[i]<min)
		{
			min=arr[i];
		}
	}
	cout<<"maximum number is"<<max<<endl;
	cout<<"minimum number is"<<min<<endl;
}
