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

string infixtopostfix(string input) {
    string output = "";
    stack<char> st;
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
    return output;
}

int calc(int a, int b, char c) {
    switch(c) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '%': return a % b;
        default: return -1;
    }
}

int evaluate(string input) {
    input = infixtopostfix(input);
    stack<int> st;
    
    int a, b, c;
    for(int i = 0; i < input.size(); i++) {
        if(pred(input[i])  == -1) {
            st.push(input[i] - '0');
            continue;
        }
        b = st.top();
        st.pop();
        a = st.top();
        st.pop();
        c = calc(a, b, input[i]);
        st.push(c);
    }
    return st.top();
}

int main() {
    cout << evaluate("((3+2)/4*(4*3)+5-(6%4))") << endl;
    return 0;
}
