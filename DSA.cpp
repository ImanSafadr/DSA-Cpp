#include <iostream>

using namespace std;

struct Node {
    int Data;
    Node* Left;
    Node* Right;
};

class BST {
private:
    Node* Root;
    int Count;

public:
    BST() : Root(NULL){}

    void Insert_BST(int Value) {
        Node* NewNode = new Node();
        Node* Parent = NULL;
        NewNode->Data = Value;
        NewNode->Left = NULL;
        NewNode->Right = NULL;

        if (Root == NULL) {
            Root = NewNode;
        } else {
            Node* Current = Root;
            while (Current != NULL) {
                Parent = Current;
                if (NewNode->Data > Current->Data) {
                    Current = Current->Right;
                } else {
                    Current = Current->Left;
                }
            }
            if (NewNode->Data > Parent->Data) {
                Parent->Right = NewNode;
            } else {
                Parent->Left = NewNode;
            }
        }
    }

    
    int InOrder(Node* Root) {
        if (Root != NULL) {
              if(Root->Left==NULL && Root->Right == NULL )
              {
                Count++;
                
              }
              if(Root->Right != NULL)
              {
                 InOrder(Root->Right);
              }
              else if(Root->Left != NULL)
              {
                InOrder(Root->Left);
              }
              return Count;
              }
             }

    Node* ReturnRoot() {
        return Root;
    }
};

int main() {
    BST bb, bb2;
    bb.Insert_BST(5);
    bb.Insert_BST(3);
    bb.Insert_BST(8);
    bb.Insert_BST(2);
    bb.Insert_BST(999);
    Node* Root = bb.ReturnRoot();
   int COUNT =  bb.InOrder(Root);
    cout << "Total Leaves are: " << COUNT << endl;
    return 0;
    }
