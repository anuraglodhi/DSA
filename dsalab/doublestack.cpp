#include <iostream>
#define MAXSIZE 10
using namespace std;

class dstack {
    int arr[MAXSIZE];
    int t1 = -1, t2 = MAXSIZE;
    int size1, size2;

    public:
    void create(int n1, int n2) {
        if(n1 + n2 > MAXSIZE) {
            cout << "Not enough space" << endl;
            return;
        }
        if(!isEmpty()) {
            cout << "Stack already exists. Use pushleft/pushright instead" << endl;
            return;
        }
        int x;
        for(int i = 0; i < n1; i++) {
            cout << "Enter element for first stack: ";
            cin >> x;
            pushleft(x);
        }
        for(int i = 0; i < n2; i++) {
            cout << "Enter element for second stack: ";
            cin >> x;
            pushright(x);
        }
    }

    void pushleft(int x) {
        if(isFull()) {
            cout << "stack is full" << endl;
            return;
        }
        t1++;
        arr[t1] = x;
    }

    void pushright(int x) {
        if(isFull()) {
            cout << "stack is full" << endl;
            return;
        }
        t2--;
        arr[t2] = x;
    }

    void popleft(int& x) {
        if(t1 == -1) {
            cout << "First stack is empty" << endl;
            return;
        }
        x = arr[t1];
        t1--;
    }

    void popright(int& x) {
        if(t2 == MAXSIZE) {
            cout << "Second stack is empty" << endl;
            return;
        }
        x = arr[t2];
        t2++;
    }

    int topleft() {
        return arr[t1];
    }

    int topright() {
        return arr[t2];
    }

    bool isFull() {
        if (t1 == t2-1)
            return true;
        return false;
    }

    bool isEmpty() {
        if(t1 == -1 && t2 == MAXSIZE)
            return true;
        return false;
    }

    int lenfirst() {
        return t1+1;
    }

    int lensecond() {
        return MAXSIZE-t2;
    }

    int total() {
        return lenfirst() + lensecond();
    }

    void output() {
        int i = t1;
        cout << "Printing stacks..." << endl;
        cout << "First: " << endl << endl;
        while(i > -1) {
            cout << "| " << arr[i] << " |" << endl;
            i--;
        }
        cout << "-----" << endl << endl;
        i = t2;
        cout << "Second: " << endl << endl;
        while(i < MAXSIZE) {
            cout << "| " << arr[i] << " |" << endl;
            i++;
        }
        cout << "-----" << endl << endl;
    }
};

int main() {
    dstack st;
    st.create(2,3);
    st.output();

    int x;
    st.popleft(x);
    st.pushleft(10);
    st.popright(x);
    st.pushright(7);
    st.pushright(10);
    st.output();
    for(int i = 0; i < 6; i++) {
        st.pushright(8);
    }
    st.output();
}
