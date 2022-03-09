#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int n) {
    if(st.empty()){
        st.push(n);
        return;
    }

    int a = st.top();
    st.pop();
    insertAtBottom(st, n);
    st.push(a);
}

void reverse(stack<int> &st) {
    if(st.size()>0) {
        int a = st.top();
        st.pop();
        reverse(st);
        insertAtBottom(st, a);
    }
}