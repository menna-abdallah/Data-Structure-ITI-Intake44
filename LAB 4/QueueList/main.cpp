#include <iostream>
using namespace std;

template <typename T>

// start node class
class Node {
public:
    // node attributes
     T data;
    Node* prev;
    Node* next;
    // constructor
    Node(T value) : data(value), prev(nullptr), next(nullptr) {}

    // node destructor
    ~Node(){
    }

}; // end node class


template <typename T>
class QueueList {
private:
    Node<T>* front;
    Node<T>* rear;

public:
    //default constructor
    QueueList() : front(nullptr), rear(nullptr) {}

    // copy constructor

     QueueList(const QueueList& que) : front(nullptr), rear(nullptr) {
        Node<T>* current = que.front;

        while (current) {
            enqueue(current->data);
            current = current->next;
        }
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return front == nullptr;
    }


    // Enqueue an element to the rear of the queue
    void enqueue(T value) {
        Node<T>* newNode = new Node<T>(value);

        // if queue is empty
        if (isEmpty()) {
                // Increment rear and front for the first time
            front = rear = newNode;
        } else {
            // increment rear
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }


    // Dequeue an element from the front of the queue
    int dequeue() {
        if (isEmpty()) {
           return T();
        }

        Node<T>* temp = front;
        T d = temp->data;

            // Only one element in the queue
        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }

        delete temp;
        return d;
    }

     ~QueueList() {
        // Deallocate memory when the queue is destroyed
         while (!isEmpty()) {
            Node<T>* temp = front;
        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }

        delete temp;
        }
    }
};

int main() {
    QueueList<int> myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

        QueueList<int> myQueue2(myQueue);


    int data1 = myQueue2.dequeue();
    cout << "Front of the queue: " << data1 << "\n"; // 10

    int data2 = myQueue.dequeue();
    cout << "Front of the queue: " << data2 << "\n"; // 20

    int data3 = myQueue.dequeue();
    cout << "Front of the queue: " << data3<< "\n"; // 30

    int data = myQueue.dequeue();
    cout << "Front of the queue: " << data << "\n"; // 0

    return 0;
}

