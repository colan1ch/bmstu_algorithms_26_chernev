#include <iostream>
#include <stack>

void sortStack(std::stack<int> &st) {
    std::stack<int> tmp;
    int cur;
    while (!st.empty()) {
        cur = st.top();
        st.pop();
        while (!tmp.empty() && tmp.top() > cur) {
            st.push(tmp.top());
            tmp.pop();
        }
        tmp.push(cur);
    }
    while (!tmp.empty()) {
        st.push(tmp.top());
        tmp.pop();
    }
}


int main() {
    std::stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);
    sortStack(st);
    while (!st.empty()) {
        std::cout << st.top() << ' ';
        st.pop();
    }    
    return 0;
}
