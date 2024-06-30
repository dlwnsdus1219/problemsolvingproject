// 스택: 후입선출!!!
#include <stack>
#include <iostream>

using namespace std;

int main(void) {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout << "st.size()" << st.size() << endl;
    cout << "st.top() -> st.pop()" << st.size() << endl;
    while(!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}