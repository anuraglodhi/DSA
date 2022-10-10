#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;
    int len = str.size();
    stack<char> st;
    int i = 0;
    while(i<len/2) {
        st.push(str[i]);
        i++;
    }
    if(len%2!=0) i++;
    while(i<len) {
        if(st.top()==str[i]) {
            st.pop();
            i++;
        }
        else {
            cout << "Not Palindrome" << endl;
            return 0;
        }
    }
    cout << "Palindrome" << endl;
}
