#include <iostream>
using namespace std;

template <typename T> class Node {
    public:
    T data;
    Node<T>* next;
};

template <typename T> class LinkedList {
    int size = 0;
    Node<T>* head = NULL;

    public:
    void create(int size) {
        if(size < 1) {
            cout << "Invalid size" << endl;
            return;
        }

        if(this->size > 0) {
            cout << "List already exists" << endl;
            return;
        }

        Node<T>* temp = new Node<T>;
        cout << "Enter element: ";
        cin >> temp->data;
        temp->next = head;
        head = temp;
        Node<T>* prev = temp;
        for(int i = 1; i < size; i++) {
            temp = new Node<T>;
            cout << "Enter element: ";
            cin >> temp->data;
            temp->next = prev->next;
            prev->next = temp;
            prev = temp;
        }
        this->size = size;
    }

    bool isEmpty() {
        if(size == 0) return true;
        return false;
    }

    int length() {
        return size;
    }

    T find(int position) {
        if(isEmpty()) {
            cout << "List is empty" << endl;
            return -999999;
        }

        if(position < 1 || position > size) {
            cout << "Invalid position" << endl;
            return -999999;
        }

        Node<T>* curr = head;
        for(int i = 1; i < position; i++) {
            curr = curr->next;
        }
        return curr->data;
    }

    int search(T element) {
        Node<T>* curr = head;
        int i = 1;
        while(curr != NULL) {
            if(curr->data == element) return i;
            i++;
            curr = curr->next;
        }
        return -1;
    }

    void insert(T element, int position) {
        if(position < 1 || position > size+1) {
            cout << "Invalid position" << endl;
            return;
        }
        Node<T>* temp = new Node<T>;
        temp->data = element;

        if(position == 1) {
            temp->next = head;
            head = temp;
            size++;
            return;
        }

        Node<T>* curr = head;

        for(int i = 1; i < position; i++) {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
        size++;
    }

    void remove(int position, T& x) {
        if(position < 1 || position > size) {
            cout << "Invalid postion" << endl;
            return;
        }

        if(position == 1) {
            Node<T>* temp = head;
            x = head->data;
            head = head->next;
            delete temp;
            size--;
            return;
        }

        Node<T>* curr = head;
        for(int i = 1; i < position-1; i++) {
            curr = curr->next;
        }
        Node<T>* temp = curr->next;
        curr->next = curr->next->next;
        x = temp->data;
        delete temp;
        size--;
    }

    void print() {
        Node<T>* curr = head;
        while(curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

};

// int main() {
//     LinkedList<int> l1;
//     l1.create(3);
//     l1.print();
//     l1.insert(10, 1);
//     l1.print();
//     int x;
//     l1.remove(3, x);
//     l1.print();
//     cout << l1.find(2) << endl;
//     cout << l1.search(3) << endl;
//     cout << l1.length() << endl;
// }