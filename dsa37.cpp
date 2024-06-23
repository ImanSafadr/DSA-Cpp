#include <iostream>
using namespace std; 
struct node 
{ 
 int info; 
 node *link; 
}; 
class llist 
{ 
private: 
 node *head; 
public: 
 llist() 
 { 
  head = NULL; 
 } 
 void insert() 
 { 
  node *temp = new node; 
  cout<<"Enter Value"; 
  cin >> temp->info; 
  temp->link = head; 
  head = temp; 
 } 
 void display() 
 { 
  node *temp = head; 
  while (temp != NULL) 
  { 
   cout << temp->info; 
   temp = temp->link; 
  } 
 } 
 void search() 
 { 
  node *temp = head; 
  int key; 
  cout <<"Enter value to be searched"; 
  cin >> key; 
  while(temp->info != key && temp->link != NULL) 
   temp = temp->link;   
  if (temp->info == key) 
   cout <<"Value found"; 
  else 
   cout <<"Value not found"; 
 } 
 void insertend(int x) 
 {   node *temp = head; 
  while (temp -> link != NULL)  
   temp = temp->link;         
  node *newer = new node;  
  newer->info = x; 
  newer->link = NULL; 
  temp->link = newer; 
 } 
 void delhead() 
 { 
  node *temp;  
  temp = head;          
  head = head->link;  
delete temp; 
} 
}; 
int main() 
{ 
llist l; 
l.insert(); 
l.insert(); 
l.insert(); 
l.display(); 
l.delhead(); 
l.display(); 
l.insertend(4); 
l.search(); 
l.display();

return 0;
}
