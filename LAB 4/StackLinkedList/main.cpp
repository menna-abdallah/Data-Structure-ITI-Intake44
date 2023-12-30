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
    next = nullptr;
    }

    // node destructor
    ~Node(){
    }

}; // end node class


template <typename T>
class StackList {
private:
    Node<T>* top;

public:
    // default constructor
 StackList() : top(nullptr) {}



 // copy constructor
  StackList(const StackList& otherStack) {
        if (otherStack.IsEmpty()) {
            top = nullptr;
            return;
        }
        // initialize top
        top = new Node<T>(otherStack.top->data);
       // top->data = otherStack.top->data;
        //////
        Node<T>* otherCurrent = otherStack.top;
        Node<T>* current = top;
        while (otherCurrent->next != nullptr) {
            otherCurrent = otherCurrent->next;
            Node<T>* newNode = new Node<T>(otherCurrent->data);
            current->next = newNode;
            current = current->next;
        }
    }

        // Check if the stack is empty
 bool IsEmpty() const {
        return top == nullptr;
    }

     void push(T value) {

        // Create a new node and make it the top of the stack
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
    }

    T pop() {
        // Remove the top element from the stack and return its value
        if (!IsEmpty()) {
            Node<T>* temp = top;
            T d = temp->data;
            top = top->next;
            delete temp;
            return d;
        }
        else{
            return T();
        }
    }
/*
     void append(T value) {
        Node<T>* newNode = new Node<T>(value);

        // if list is empty
        if (IsEmpty()) {
            top = newNode;
            // newNode->next = nullptr;
        } else {
            // find the last node >> start with head
            Node<T>* current = top;
            while (current->next != nullptr) {
                current = current->next;
                // if current ->next = nullptr then this is the last node
            }
            // append new node
            current->next = newNode;
            // link new node with the last one
            newNode->next = nullptr;
        }
    }
*/
    ~StackList() {
        // Destructor to deallocate memory when the stack is destroyed
        while (!IsEmpty()) {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

    int main() {

    StackList<int> myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    StackList<int> myStack2(myStack);


     int data1 = myStack2.pop();
     cout << "Top element: " << data1 << endl; //30

     int data2 = myStack.pop();
     cout << "Top element after pop: " << data2 << endl; // 20

     int data3= myStack.pop();
     cout << "Top element after pop: " << data3 << endl; //10

     int data = myStack.pop();
     cout << "Top element after pop: " << data << endl; // empty // T() >> 0

    return 0;
}
