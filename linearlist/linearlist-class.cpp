#include <iostream>
using namespace std;

template <typename T> class LinearList {
    int size = 0;
    const static int MAXSIZE = 100;
    T arr[MAXSIZE];

    public:

    void create(int size) {
        if(size < 1 || size > MAXSIZE) {
            cout << "Invalid size" << endl;
            return;
        }

        if(this->size > 0) {
            cout << "List already exists" << endl;
            return;
        }

        for(int i = 0;  i < size; i++) {
            cout << "Enter element: ";
            cin >> arr[i];
        }
        this->size = size;
    }

    bool isEmpty() {
        if(size == 0) return true;
        return false;
    }

    bool isFull() {
        if(size == MAXSIZE) return true;
        return false;
    }

    int length() {
        return size;
    }

    T find(int position) {
        if(position < 1 || position > size) {
            cout << "Invalid position" << endl;
            return -999999;
        }

        return arr[position-1];
    }

    int search(T element) {
        if(size == 0) {
            cout << "List is empty" << endl;
            return -1;
        }

        for(int i = 0; i < size; i++) {
            if(arr[i] == element) return i+1;
        }
        return -1;
    }

    void insert(T element, int position) {
        if(isFull()) {
            cout << "List is full" << endl;
            return;
        }

        if(position < 1 || position > size + 1) {
            cout << "Invalid position" << endl;
            return;
        }

        for(int i = size-1; i <= position-1; i++) {
            arr[i+1] = arr[i];
        }
        arr[position-1] = element;
        size++;
    }

    void remove(int position, T& x) {
        if(position < 1 || position > size) {
            cout << "Invalid position" << endl;
            return;
        }

        x = arr[position-1];
        for(int i = position-1; i < size-1; i++) {
            arr[i] = arr[i+1];
        }
        size--;
    }

    void print() {
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// int main() {
//     LinearList<int> l1;
//     cout << l1.length() << endl;
//     l1.create(5);
//     l1.print();
//     l1.insert(10, 6);
//     l1.print();
//     int x;
//     l1.remove(2, x);
//     l1.print();
//     cout << x << endl;
//     cout << l1.find(3) << endl;
//     cout << l1.search(4) << endl;
// }