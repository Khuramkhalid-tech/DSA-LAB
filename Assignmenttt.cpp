#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class DoublyNode : public Node {
public:
    Node* prev;

    DoublyNode(int value) : Node(value) {
        prev = NULL;
    }
};

class CircularNode : public Node {
public:
    CircularNode(int value) : Node(value) {}
};

class LinkedList {
protected:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Function to add a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to add a node at the beginning of the list
    void insertAtStart(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to add a node at a specific index
    void insertAtIndex(int value, int index) {
        if (index < 0) {
            cout << "Invalid index. Cannot insert at a negative index." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            int currentIndex = 0;
            while (current != NULL && currentIndex < index - 1) {
                current = current->next;
                currentIndex++;
            }
            if (current == NULL) {
                cout << "Invalid index. Cannot insert at the specified index." << endl;
                return;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Function to delete a node at the start of the list
    void deleteAtStart() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete from an empty list." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Function to delete a node at the end of the list
    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete from an empty list." << endl;
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }

        delete current->next;
        current->next = NULL;
    }

    // Function to delete a node at a specific index
    void deleteAtIndex(int index) {
        if (index < 0) {
            cout << "Invalid index. Cannot delete at a negative index." << endl;
            return;
        }

        if (head == NULL) {
            cout << "List is empty. Cannot delete from an empty list." << endl;
            return;
        }

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            int currentIndex = 0;
            while (current->next != NULL && currentIndex < index - 1) {
                current = current->next;
                currentIndex++;
            }
            if (current->next == NULL) {
                cout << "Invalid index. Cannot delete at the specified index." << endl;
                return;
            }
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // Function to print the entire linked list
    void printList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

class DoublyLinkedList : public LinkedList {
public:
    DoublyLinkedList() : LinkedList() {}

    // Function to add a node at the end of the doubly linked list
    void insertAtEnd(int value) {
        DoublyNode* newNode = new DoublyNode(value);
        if (head == NULL) {
            head = newNode;
        } else {
            DoublyNode* current = static_cast<DoublyNode*>(head);
            while (current->next != NULL) {
                current = static_cast<DoublyNode*>(current->next);
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    // Function to add a node at the beginning of the doubly linked list
    void insertAtStart(int value) {
        DoublyNode* newNode = new DoublyNode(value);
        newNode->next = head;
        if (head != NULL) {
            static_cast<DoublyNode*>(head)->prev = newNode;
        }
        head = newNode;
    }

    // Function to add a node at a specific index in the doubly linked list
    void insertAtIndex(int value, int index) {
        if (index < 0) {
            cout << "Invalid index. Cannot insert at a negative index." << endl;
            return;
        }

        DoublyNode* newNode = new DoublyNode(value);
        if (index == 0) {
            newNode->next = head;
            if (head != NULL) {
                static_cast<DoublyNode*>(head)->prev = newNode;
            }
            head = newNode;
        } else {
            DoublyNode* current = static_cast<DoublyNode*>(head);
            int currentIndex = 0;
            while (current != NULL && currentIndex < index - 1) {
                current = static_cast<DoublyNode*>(current->next);
                currentIndex++;
            }
            if (current == NULL) {
                cout << "Invalid index. Cannot insert at the specified index." << endl;
                return;
            }
            newNode->next = current->next;
            if (current->next != NULL) {
                static_cast<DoublyNode*>(current->next)->prev = newNode;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    // Function to delete a node at the end of the doubly linked list
    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete from an empty list." << endl;
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        DoublyNode* current = static_cast<DoublyNode*>(head);
        while (current->next->next != NULL) {
            current = static_cast<DoublyNode*>(current->next);
        }

        delete current->next;
        current->next = NULL;
    }

    // Function to delete a node at the start of the doubly linked list
    void deleteAtStart() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete from an empty list." << endl;
            return;
        }

        DoublyNode* temp = static_cast<DoublyNode*>(head);
        head = head->next;
        if (head != NULL) {
            static_cast<DoublyNode*>(head)->prev = NULL;
        }
        delete temp;
    }

    // Function to delete a node at a specific index in the doubly linked list
    void deleteAtIndex(int index) {
        if (index < 0) {
            cout << "Invalid index. Cannot delete at a negative index." << endl;
            return;
        }

        if (head == NULL) {
            cout << "List is empty. Cannot delete from an empty list." << endl;
            return;
        }

        if (index == 0) {
            DoublyNode* temp = static_cast<DoublyNode*>(head);
            head = head->next;
            if (head != NULL) {
                static_cast<DoublyNode*>(head)->prev = NULL;
            }
            delete temp;
        } else {
            DoublyNode* current = static_cast<DoublyNode*>(head);
            int currentIndex = 0;
            while (current->next != NULL && currentIndex < index - 1) {
                current = static_cast<DoublyNode*>(current->next);
                currentIndex++;
            }
            if (current->next == NULL) {
                cout << "Invalid index. Cannot delete at the specified index." << endl;
                return;
            }
            DoublyNode* temp = static_cast<DoublyNode*>(current->next);
            current->next = current->next->next;
            if (current->next != NULL) {
                static_cast<DoublyNode*>(current->next)->prev = current;
            }
            delete temp;
        }
    }

    // Function to print the entire doubly linked list
    void printList() {
        DoublyNode* current = static_cast<DoublyNode*>(head);
        while (current != NULL) {
            cout << current->data << " <-> ";
            current = static_cast<DoublyNode*>(current->next);
        }
        cout << "nullptr" << endl;
    }
};

class CircularLinkedList : public LinkedList {
public:
    CircularLinkedList() : LinkedList() {}

    // Function to add a node at the end of the circular linked list
    void insertAtEnd(int value) {
        Node* newNode = new CircularNode(value);
        if (head == NULL) {
            head = newNode;
            newNode->next = newNode; // Point to itself for circularity
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head; // Make it circular
        }
    }

    // Function to add a node at the beginning of the circular linked list
    void insertAtStart(int value) {
        Node* newNode = new CircularNode(value);
        if (head == NULL) {
            head = newNode;
            newNode->next = newNode; // Point to itself for circularity
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head; // Make it circular
            head = newNode;
        }
    }

    // Function to add a node at a specific index in the circular linked list
    void insertAtIndex(int value, int index) {
        if (index < 0) {
            cout << "Invalid index. Cannot insert at a negative index." << endl;
            return;
        }

        Node* newNode = new CircularNode(value);
        if (head == NULL) {
            head = newNode;
            newNode->next = newNode; // Point to itself for circularity
        } else if (index == 0) {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head; // Make it circular
            head = newNode;
        } else {
            Node* current = head;
            int currentIndex = 0;
            while (current->next != head && currentIndex < index - 1) {
                current = current->next;
                currentIndex++;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Function to delete a node at the end of the circular linked list
    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete from an empty list." << endl;
            return;
        }

        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* current = head;
        while (current->next->next != head) {
            current = current->next;
        }

        delete current->next;
        current->next = head;
    }

    // Function to delete a node at the start of the circular linked list
    void deleteAtStart() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete from an empty list." << endl;
            return;
        }

        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }

        Node* temp = head;
        head = head->next;
        current->next = head;
        delete temp;
    }

    // Function to delete a node at a specific index in the circular linked list
    void deleteAtIndex(int index) {
        if (index < 0) {
            cout << "Invalid index. Cannot delete at a negative index." << endl;
            return;
        }

        if (head == NULL) {
            cout << "List is empty. Cannot delete from an empty list." << endl;
            return;
        }

        if (index == 0) {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            Node* temp = head;
            head = head->next;
            current->next = head;
            delete temp;
        } else {
            Node* current = head;
            int currentIndex = 0;
            while (current->next != head && currentIndex < index - 1) {
                current = current->next;
                currentIndex++;
            }
            if (current->next == head) {
                cout << "Invalid index. Cannot delete at the specified index." << endl;
                return;
            }
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // Function to print the entire circular linked list
    void printList() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
        cout << "Head" << endl;
    }
};

int main() {
    LinkedList myList;
    DoublyLinkedList myDoublyList;
    CircularLinkedList myCircularList;

    while (true) {
        int choice;
        cout << "Choose a list and operation:" << endl;
        cout << "1. Singly Linked List: Insert at end" << endl;
        cout << "2. Singly Linked List: Insert at start" << endl;
        cout << "3. Singly Linked List: Insert at index" << endl;
        cout << "4. Singly linked list: delete at start" << endl;
        cout << "5. Singly linked list: delete at end" << endl;
        cout << "6. Singly Linked List: Delete at index" << endl;
        cout << "7. Singly Linked List: Print list" << endl;
        cout << "8. Doubly Linked List: Insert at end" << endl;
        cout << "9. Doubly Linked List: Insert at start" << endl;
        cout << "10. Doubly Linked List: Insert at index" << endl;
        cout << "11. Doubly Linked List: delete at end" << endl;
        cout << "12. Doubly Linked List: delete at start" << endl;
        cout << "13. Doubly Linked List: delete at index" << endl;
        cout << "14. Doubly Linked List: Print list" << endl;
        cout << "15. Circular Linked List: Insert at end" << endl;
        cout << "16. Circular Linked List: Insert at start" << endl;
        cout << "17. Circular Linked List: Insert at index" << endl;
        cout << "18. Circular Linked List: delete at end" << endl;
        cout << "19. Circular Linked List: delete at start" << endl;
        cout << "20. Circular Linked List: delete at index" << endl;
        cout << "21. Circular Linked List: Print list" << endl;
        cout << "22. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        int value, index;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at end: ";
                cin >> value;
                myList.insertAtEnd(value);
                break;
            case 2:
                cout << "Enter value to insert at start: ";
                cin >> value;
                myList.insertAtStart(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter index to insert at: ";
                cin >> index;
                myList.insertAtIndex(value, index);
                break;
            case 4:
                myList.deleteAtStart();
                break;
            case 5:
                myList.deleteAtEnd();
                break;
            case 6:
                cout << "Enter index to delete: ";
                cin >> index;
                myList.deleteAtIndex(index);
                break;
            case 7:
                cout << "Singly Linked List: ";
                myList.printList();
                break;
            case 8:
                cout << "Enter value to insert at end: ";
                cin >> value;
                myDoublyList.insertAtEnd(value);
                break;
            case 9:
                cout << "Enter value to insert at start: ";
                cin >> value;
                myDoublyList.insertAtStart(value);
                break;
            case 10:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter index to insert at: ";
                cin >> index;
                myDoublyList.insertAtIndex(value, index);
                break;
            case 11:
                myDoublyList.deleteAtEnd();
                break;
            case 12:
                myDoublyList.deleteAtStart();
                break;
            case 13:
                cout << "Enter index to delete: ";
                cin >> index;
                myDoublyList.deleteAtIndex(index);
                break;
            case 14:
                cout << "Doubly Linked List: ";
                myDoublyList.printList();
                break;
            case 15:
                cout << "Enter value to insert at end: ";
                cin >> value;
                myCircularList.insertAtEnd(value);
                break;
            case 16:
                cout << "Enter value to insert at start: ";
                cin >> value;
                myCircularList.insertAtStart(value);
                break;
            case 17:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter index to insert at: ";
                cin >> index;
                myCircularList.insertAtIndex(value, index);
                break;
            case 18:
                myCircularList.deleteAtEnd();
                break;
            case 19:
                myCircularList.deleteAtStart();
                break;
            case 20:
                cout << "Enter index to delete: ";
                cin >> index;
                myCircularList.deleteAtIndex(index);
                break;
            case 21:
                cout << "Circular Linked List: ";
                myCircularList.printList();
                break;
            case 22:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

