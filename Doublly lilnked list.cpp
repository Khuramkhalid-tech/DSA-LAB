
// Complete doubly linked List

#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next;
    Node* prev;

public:
    Node* head;

    Node() {
        head = NULL;
    }
    //It is working fine
    void insert_at_beg(int data) {
        Node* newNode = new Node(); // Create a new node
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    //It is working fine
    void insert_at_end(int data){
    	Node *newNode = new Node();
    	newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        
        if (head== NULL){
        	head = newNode;
		}
		else {
			// node pointer that will traverse
			Node *ptr;
			
			ptr = head;
			
			while (ptr->next != NULL){
				ptr= ptr->next;
			}
			// now we are at last node
			ptr->next = newNode;
			newNode->prev = ptr;
		}
	}



  //  void insert_at_index(int data, int pos){
    //	Node *newNode = new Node();
    //	newNode->data = data;
      //  newNode->next = NULL;
        //newNode->prev = NULL;
        
    	// of course we we would have a llisnked list to insert in index so we do not need if
    	
    	//Node *ptr;
    	//ptr =head;
    	//Node *p;
    	
    	//while (ptr->data!= pos){
    	//	p->next = ptr;
    	//	ptr= ptr->next;
	//	}
		// Now we are at index 
		
	//	newNode->next = ptr;
	//	newNode->prev = ptr->prev;
	//	ptr->prev = newNode;
	//	p->next = newNode;
		
	//}


void insert_at_index(int data, int pos) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    // If the list is empty or pos is 0, insert at the beginning
    if (head == NULL || pos == 0) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
    } else {
        Node* ptr = head;
        int index = 0;

        // Traverse to the node just before the desired position
        while (ptr->next != NULL && index < pos - 1) {
            ptr = ptr->next;
            index++;
        }

        // Check if we reached the desired position or the end of the list
        if (index == pos - 1) {
            newNode->next = ptr->next;
            newNode->prev = ptr;
            if (ptr->next != NULL) {
                ptr->next->prev = newNode;
            }
            ptr->next = newNode;
        } else {
            // If pos is out of bounds, insert at the end
            ptr->next = newNode;
            newNode->prev = ptr;
        }
    }
}
// its working!
   void delete_at_beg(){
	
	    if (head  == NULL){
	        	delete(head);
	    }
	    
	    else{
	    Node *p;
	    
	    p = head;
	    head = head->next;
	    head->prev = NULL;
	    delete(p);   
        }
    }
    
    void delete_at_end(){
    	
    	if (head  == NULL){
	        	delete(head);
	    }
	    
	    else {
	    	Node *ptr = head;
	    	
	    	while (ptr->next!= NULL){
	    		ptr=ptr->next;
			}
			
			ptr->prev->next= NULL;
			// ptr->prev = NULL;
			
			delete(ptr);
		}
	}
	
//	void delete_at_index(int pos){
//		Node *ptr;
//		if (head == NULL || pos == 0){
//			ptr = head;
//			head = head->next;
//			delete(ptr);
//		}
//		else{
//			ptr = head;
//			int index =0;
			
//			while (ptr->next != NULL && index != pos) {
  //             ptr = ptr->next;
    //           index++;
        //    }
      //      ptr->prev->next= ptr->next;
            
          //  ptr->next->prev = ptr->prev;
            
            //delete (ptr);
	//	}
		
	//}
      
	  
	  void delete_at_index(int pos) {
    if (head == NULL) {
        // List is empty, nothing to delete
        return;
    }

    if (pos == 0) {
        // Deleting the first node
        Node* ptr = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete(ptr);
        return;
    }

    int index = 0;
    Node* ptr = head;

    while (ptr != NULL && index != pos) {
        ptr = ptr->next;
        index++;
    }

    if (ptr == NULL) {
        // The desired position is out of bounds
        return;
    }

    // Adjust the pointers to skip the node at the desired position
    if (ptr->prev != NULL) {
        ptr->prev->next = ptr->next;
    }
    if (ptr->next != NULL) {
        ptr->next->prev = ptr->prev;
    }

    delete(ptr);
}
  
    void traverse() {
        Node* ptr = head;
        while (ptr != NULL) {
            cout << "Element: " << ptr->data << endl;
            ptr = ptr->next;
        }
    }
    
};

int main() {
    Node n;
    n.insert_at_beg(4);
    n.insert_at_beg(7);
    n.insert_at_beg(10);
    n.insert_at_beg(7);
    n.insert_at_end(10);
    n.insert_at_index(7, 10);
    n.delete_at_beg();
    n.delete_at_end();
    n.delete_at_index(7);
    n.traverse();
    return 0;
}

