#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Function to add a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
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
            std::cout << "Invalid index. Cannot insert at a negative index." << std::endl;
            return;
        }

        Node* newNode = new Node(value);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            int currentIndex = 0;
            while (current != nullptr && currentIndex < index - 1) {
                current = current->next;
                currentIndex++;
            }
            if (current == nullptr) {
                std::cout << "Invalid index. Cannot insert at the specified index." << std::endl;
                return;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Function to delete a node at a specific index
    void deleteAtIndex(int index) {
        if (index < 0) {
            std::cout << "Invalid index. Cannot delete at a negative index." << std::endl;
            return;
        }

        if (head == nullptr) {
            std::cout << "List is empty. Cannot delete from an empty list." << std::endl;
            return;
        }

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            int currentIndex = 0;
            while (current->next != nullptr && currentIndex < index - 1) {
                current = current->next;
                currentIndex++;
            }
            if (current->next == nullptr) {
                std::cout << "Invalid index. Cannot delete at the specified index." << std::endl;
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
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    LinkedList myList;

    while (true) {
        int choice;
        std::cout << "Choose an operation:" << std::endl;
        std::cout << "1. Insert at end" << std::endl;
        std::cout << "2. Insert at start" << std::endl;
        std::cout << "3. Insert at index" << std::endl;
        std::cout << "4. Delete at index" << std::endl;
        std::cout << "5. Print list" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        int value, index;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert at end: ";
                std::cin >> value;
                myList.insertAtEnd(value);
                break;
            case 2:
                std::cout << "Enter value to insert at start: ";
                std::cin >> value;
                myList.insertAtStart(value);
                break;
            case 3:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                std::cout << "Enter index to insert at: ";
                std::cin >> index;
                myList.insertAtIndex(value, index);
                break;
            case 4:
                std::cout << "Enter index to delete: ";
                std::cin >> index;
                myList.deleteAtIndex(index);
                break;
            case 5:
                std::cout << "Linked List: ";
                myList.printList();
                break;
            case 6:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
