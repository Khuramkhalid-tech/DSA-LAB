#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next;

public:
    Node* head;

    Node() {
        head = NULL;
    }

    void insert_beg(int n) {
        Node* p = new Node();
        p->data = n;
        p->next = head;
        head = p;
    }

    void insert_at_value(int pos, int n) {
        if (head == NULL) {
            cout << "\nNo data is in the list.." << endl;
            return;
        } else {
            Node* ptr = head;
            while (ptr != NULL && ptr->data != pos) {
                ptr = ptr->next;
            }
            if (ptr == NULL) {
                cout << "Data " << pos << " not found in the list." << endl;
                return;
            }
            Node* p = new Node();
            p->data = n;
            p->next = ptr->next;
            ptr->next = p;
        }
    }

    void insert_BA_index(int index, int data1, int data2) {
        Node* p = head;
        Node* ptr = NULL;

        while (p != NULL && p->data != index) {
            ptr = p;
            p = p->next;
        }

        if (p == NULL) {
            cout << "Data " << index << " not found in the list." << endl;
            return;
        }

        Node* new_node_before = new Node();
        new_node_before->data = data1;
        new_node_before->next = p;

        Node* new_node_after = new Node();
        new_node_after->data = data2;
        new_node_after->next = p->next;

        if (ptr == NULL) {
            head = new_node_before;
        } else {
            ptr->next = new_node_before;
        }

        p->next = new_node_after;
    }

    void display() {
        Node* ptr = head;
        while (ptr != NULL) {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
};

int main() {
    Node n;
    n.insert_beg(20);
    n.insert_beg(30);
    n.insert_beg(3);
    n.insert_at_value(30, 50);
    n.insert_BA_index(30, 4, 5);
    n.display();
    return 0;
}
