#include <iostream>
#define MAXSIZE 10
using namespace std;

class Queue {
    public:
    int q[MAXSIZE];
    int front;
    int rear;
    
    Queue() : front(-1), rear(-1) {};
    
    void enqueue(int x) {
        if(isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if(front == -1 && rear == -1) {
            front++;
        }
        rear++;
        q[rear] = x;
    }
    
    void dequeue(int& x) {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        x = q[front];
        front++;
    }
    
    int isEmpty() {
        if(front == -1 && rear == -1) return 1;
        return 0;
    }
    
    int isFull() {
        if(rear == MAXSIZE-1) return 1;
        return 0;
    }
    
    int first() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return -999999;
        }
        return q[front];
    }
    int last() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return -999999;
        }
        return q[rear];
    }
    
    void output() {
        for(int i = front; i <= rear; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }
    
    void create(int n) {
        if(n < 1 || n > MAXSIZE) {
            cout << "invalid length" << endl;
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
//     cout << q.front << q.rear << endl;
//     q.create(3);
//     q.enqueue(6);
//     int x;
//     q.dequeue(x);
//     cout << x << endl;
//     q.output();

//     return 0;
// }
