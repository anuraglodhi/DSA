#include <iostream>
#include <stack>
using namespace std;

int pred(char a) {
    switch(a) {
        case '$': return 0;
        case '(': return 0;
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '%': return 2;
        default: return -1;
    }
}

int main() {
    string input, output = "";
    stack<char> st;
    cout << "Infix: ";
    cin >> input;
    st.push('$');
    for(int i = 0; i < input.size(); i++) {
        char a = input[i];

        if(a == '(') {
            st.push('(');
            continue;
        }
        if(a == ')') {
            while(st.top() != '(') {
                output = output + st.top();
                st.pop();
            }
            st.pop();
            continue;
        }

        int p = pred(a);
        if(p == -1) {
            output = output + a;
            continue;
        }
        while(pred(st.top()) >= p) {
            output = output + st.top();
            st.pop();
        }
        st.push(a);
    }
    while(st.top() != '$') {
        output = output + st.top();
        st.pop();
    }
    cout << "Postfix: " << output << endl;
    return 0;
}
