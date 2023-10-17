#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL; // Use NULL here if necessary
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL; // Use NULL here if necessary
    }

    void push(int data) {
        Node* new_node = new Node(data);
        new_node->next = top;
        top = new_node;
    }

    void pop() {
        if (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool isEmpty() {
        return top == NULL; // Use NULL here if necessary
    }

    int peek() {
        if (!isEmpty()) {
            return top->data;
        }
        else {
            exit(1);
        }
    }
};

int main() {
    Stack myStack;
    string s;
	cout << "Enter string for reversal: "<< endl;
    cin >> s;
    
    
      for (int i = 0; i < s.length(); i++) {
        myStack.push(s[i]);
    }

    // Pop characters from the stack to get the reversed string
    string reversed;
    while (!myStack.isEmpty()) {
        reversed += myStack.peek();
        myStack.pop();
    }

    cout << "Reversed string: " << reversed << endl;
    
   return 0;
}

