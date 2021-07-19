#include <iostream>
#include <string>
#include <stack>

using namespace std;

string inorderToPostOrder(string inorder) {
    stack<char> st;
    string postorder;

    for (int idx = 0; idx < inorder.size(); idx++) {
        if ('A' <= inorder[idx] && inorder[idx] <= 'Z') {
            postorder.push_back(inorder[idx]);
        } else {
            switch(inorder[idx]) {
                case '(':
                st.push(inorder[idx]);
                break;
                case '*':
                case '/':
                while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                    postorder.push_back(st.top());
                    st.pop();
                }
                st.push(inorder[idx]);
                break;
                case '+':
                case '-':
                while (!st.empty() && st.top() != '(') {
                    postorder.push_back(st.top());
                    st.pop();
                }
                st.push(inorder[idx]);
                break;
                case ')':
                while (!st.empty() && st.top() != '(') {
                    postorder.push_back(st.top());
                    st.pop();
                }
                st.pop();
                break;
            }
        }
    }

    while (!st.empty()) {
        postorder.push_back(st.top());
        st.pop();
    }
    
    return postorder;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio;

    string inorder;

    cin >> inorder;

    cout << inorderToPostOrder(inorder) << endl;
}