#include <iostream>
#include <string>
using namespace std;

class node {
public:
    char data;
    node* next;

    node(char val) {
        data = val;
        next = NULL;
    }
};

class stack {
public:
    node* head;
    stack() {
        head = NULL;
    }

    bool isEmpty() {
        return (head == NULL);
    }

    void push(char val) {
        node* newnode = new node(val);
        newnode->next = head;
        head = newnode;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return '\0'; // Return a default character
        }
        node* temp = head;
        char val = temp->data;
        head = temp->next;
        delete temp;
        return val;
    }

    void empty() {
        char ans;
        while (!isEmpty()) {
            ans = pop();
        }
    }
};

bool areBracketsBalanced(const string& input) {
    stack stk;

    for (char c : input) {
        if (c == '[' || c == '{' || c == '(') {
            stk.push(c);
        } else if (c == ']' || c == '}' || c == ')') {
            if (stk.isEmpty()) {
                return false; // Unmatched closing bracket
            }

            char openBracket = stk.pop();
            if ((c == ']' && openBracket != '[') ||
                (c == '}' && openBracket != '{') ||
                (c == ')' && openBracket != '(')) {
                return false; // Mismatched brackets
            }
        }
    }

    return stk.isEmpty();
}

int main() {
    string input;
    cout << "Enter string: ";
    cin >> input;

    if (areBracketsBalanced(input)) {
        cout << "Equation is balanced" << endl;
    } else {
        cout << "Equation is not balanced" << endl;
    }

    return 0;
}
