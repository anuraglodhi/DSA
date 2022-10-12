#include <iostream>
using namespace std;

typedef struct Node {
    int data;
    struct Node* link;
} Node;

class Queue {
    Node* front;
    Node* rear;
    
    public:
    Queue() : front(NULL), rear(NULL) {};
    
    void enqueue(int x) {
        if(isFull()) {
            cout << "queue is full" << endl;
            return;
        }
        Node* temp = new Node();
        temp->data = x;
        if(front == NULL && rear == NULL) {
            front = temp;
            rear = temp;
            return;
        }
        rear->link = temp;
        rear = temp;
    }
    
    void dequeue(int& x) {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        x = front->data;
        Node* temp = front;
        front = front->link;
        delete temp;
    }
    
    int isEmpty() {
        if(front == NULL && rear == NULL) return 1;
        return 0;
    }
    
    int isFull() {
        Node* temp = new Node();
        if(temp == NULL) return 1;
        delete temp;
        return 0;
    }
    
    int first() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return -999999;
        }
        return front->data;
    }
    int last() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return -999999;
        }
        return rear->data;
    }
    
    void output() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        while(temp != rear->link) {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << endl;
    }
    
    void create(int n) {
        if(n < 1) {
            cout << "Invalid size" << endl;
            return;
        }
        int x;
        for(int i = 0; i < n; i++) {
            cout << "Enter element: ";
            cin >> x;
            enqueue(x);
        }
    }
};

// int main()
// {
    
//     Queue q;
//     q.create(3);
//     q.enqueue(6);
//     int x;
//     q.dequeue(x);
//     cout << x << endl;
//     q.output();

//     return 0;
// }
