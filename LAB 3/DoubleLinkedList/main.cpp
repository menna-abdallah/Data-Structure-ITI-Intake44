#include <iostream>
using namespace std;

template <typename T>

// start node class
class Node {
public:
    // node attributes
    T data;
    Node* next;
    Node* prev;

    // Node constructor
    Node (T value) {
    data = value;
    next = prev = nullptr;
    }

    // node destructor
    ~Node(){
    }

}; // end node class


template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head; // pointer to the first node

public:
    // default Constructor
    DoublyLinkedList() : head(nullptr) {} // initialize the list

    // Copy Constructor
    DoublyLinkedList(const DoublyLinkedList& List) {
        head = nullptr; // initialize the list
        Node<T>* current = List.head;  // get the head of the copied list

        // loop through the list using current
        // start with current = head to point to the first node
        while (current != nullptr) {
                // start copy list values to the new list using addToend
            addToend(current->data);
        // point to the next node
            current = current->next;
        }
    }


     // IsEmpty
    bool IsEmpty() {
        return head == nullptr;
    }


    // Add at the end (append)
    void addToend(T value) {
        Node<T>* newNode = new Node<T>(value);

        // if list is empty
        if (IsEmpty()) {
            head = newNode;
            newNode->next = nullptr;
        } else {
            // find the last node >> start with head
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
                // if current ->next = nullptr then this is the last node
            }
            // append new node
            current->next = newNode;
            // link new node with the last one
            newNode->prev = current;
        }
    }

    // add at the beginnig
    void addTofront(T value) {
        Node<T>* newNode = new Node<T>(value);

        // if list is empty
        if (IsEmpty()) {
            head = newNode;
            newNode->next = nullptr;
        } else {
            // the new node to the head node
            newNode->next = head;
            head=newNode;
        }
    }

    // Display
    void Display() const {
        // get data from nodes >> start with head
        Node<T>* current = head;
        while (current) {
            cout << current->data << " , ";
            current = current->next;
        }
        cout << endl;
    }


    // ClearList
    void ClearList() {
        head = nullptr;
        cout <<"list is clear" << endl;
    }


    /*

      void ClearList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    */


    // Search
    bool Search(T value) const {
         // get data from nodes >> start with head
        Node<T>* current = head;
        while (current) {

            if (current->data == value) {
                return true; // found
            }
            current = current->next; // point to the next node
        }
        return false;
    }

    // Delete
   void Delete(T value) {

       // get data from nodes >> start with head

        Node<T>* current = head;
        while (current) {
                // find the node
            if (current->data == value) {
                    // if it is not the head node
                if (current->prev) {
                    current = current->next;
                } else {
                    head = current->next;
                }
                    // if it is not the tail
                if (current->next) {
                    current = current->prev;
                }

                delete current;
                break;
            }
            // continue to search
            current = current->next;
        }
    }


    // InsertAfter
    void InsertAfter(T Value1, T Value2) {
        // find Value1 >> start with head
        Node<T>* current = head;
        while (current) {
                // find the node to insert after
            if (current->data == Value1) {
                // creat new node
                Node<T>* newNode = new Node<T>(Value2);
                    // if not the tail
                if (current->next) {
                // link new node to the list
                newNode->next = current->next;
                current->next = newNode;
                }
                // if it is the tail node
            else{

                current->next = newNode;
                newNode->next = nullptr;
            }
            }
             // continue to search
            current = current->next;
        }
    }


    // Bubble Sort
    void BubbleSort() {
        // empty or had one node
        if (IsEmpty()) {
            return; // empty list
        }
        if(head->next == nullptr){
            cout<< "alredy sorted there is one node in this list";
        }
        // set flag = true
        bool flag = true;
        //initialize first counter
        Node<T>* current1 = head;
        // outer loop
        while(flag){
        // initialize second counter
        Node<T>* current2 = head;
                //inner loop
                do{
                        // start loop through the list
                if (current2->data > current2->next->data) {
                   swap(current2->data, current2->next->data);
                }
                // increment inner loop
                current2 = current2->next;

                }while (current2->next != nullptr); // end inner loop

                //increment outer loop
                current1 = current1->next;

                //end outer loop
            if (current1->next == nullptr){
                flag = false;
            }
            }
    }
    void swap(T &item1,T &item2)
{
    T temp;
    temp = item1;
    item1=item2;
    item2=temp;
}
};

int main() {
    DoublyLinkedList<int> myList;

    // is empty
    cout << "At first is list is empty?";
    cout << (myList.IsEmpty() ? " Yes" : " No") << endl;

    // append
    myList.addToend(3);
    myList.addToend(1);
    myList.addToend(4);
    myList.addToend(1);
    myList.addToend(5);

    //display
     cout << "Display List: ";
     myList.Display();

    //add to front
     myList.addTofront(8);
     cout << "Display The List After Insert 8 at the front : ";
     myList.Display();

    // sort
    myList.BubbleSort();
    cout << "Sorted List: ";
    myList.Display();

    // insert between two values
    myList.InsertAfter(5, 10);
    cout << "List after InsertAfter: ";
    myList.Display();

     myList.BubbleSort();
     cout<< "sort again : ";
     myList.Display();

     // delete
    myList.Delete(1);
    cout << "List after Delete: ";
    myList.Display();


    // clear
    myList.ClearList();

    cout << "Is List Empty after ClearList? " << (myList.IsEmpty() ? "Yes" : "No") << endl;

    myList.Display();

    return 0;
}
