#include <iostream>
using namespace std;
class Stack {
private:
    static const int MAX_SIZE = 100; // Maximum stack size
    int elements[MAX_SIZE];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    void push(int value) {
        if (topIndex < MAX_SIZE - 1) {
            elements[++topIndex] = value;
        } else {
            cout << "Stack is full. Cannot push." << endl;
        }
    }

    void pop() {
        if (!empty()) {
            topIndex--;
        } else {
            cout << "Stack is empty. Cannot pop." << endl;
        }
    }

    int top() {
        if (!empty()) {
            return elements[topIndex];
        } else {
            cout << "Stack is empty." << endl;
            return -1; // Return a default value in case the stack is empty
        }
    }

    bool empty() {
        return topIndex == -1;
    }

    int size() {
        return topIndex + 1;
    }
};

int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Stack size: " << myStack.size() << endl;
    cout << "Top element: " << myStack.top() << endl;

    myStack.pop();
    cout << "Popped an element." << endl;

     cout << "Stack size: " << myStack.size() << endl;
     cout << "Top element: " << myStack.top() << endl;

    return 0;
}

