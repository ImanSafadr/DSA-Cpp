#include <iostream>
using namespace std;
const int SIZE = 10;
class Array
{
private:
	int a[SIZE];
	int n;
public:
	Array()
	{
		for (int i=0;i<SIZE;i++)
			a[i] = 0;
		n = 0;
	}
	void read()
	{
		char ch = 'y';
		while (ch != 'n')
		{
			cout << "Enter the element";
			cin >>a[n];
			n++;
			cout <<"Do you want to Continue?";
			cin >> ch;
		}
	}
	void display()
	{
		for (int i=0;i<n;i++)
			cout << a[i]<< endl;
	}
	void del()
	{
		int index;
		cout << "Enter index";
		cin >> index;
		for (int i=index;i<n-1;i++)
			a[i] = a[i+1];
		n--;
		display();
	}
	void insert()
	{
		int index;
		cout << "Enter index";
		cin >> index;
		for (int i=n;i>index;i--)
			{a[i] = a[i-1];
		cout << "Enter Value";
		cin >> a[i];
		n++;}
		display();
	}
	void sort()
	{
		for (int i=0;i<n-1;i++)
			for (int j= 0;j<n-i-1;j++)
				if (a[j+1] < a[j])
				{
					int temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
	}
	void merge(Array a1, Array a2)
	{
	 
	}
};
int main()
{
	Array itm, a2, a3;
	itm.read();
	itm.display();
	a2.read();
	a2.display();
	itm.sort();
	itm.display();
	a2.sort();
	a2.display();
	a3.merge(itm,a2);
	a3.display();
itm.del();
	itm.insert();
}



