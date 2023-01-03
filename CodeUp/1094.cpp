#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n, num;
    stack<int> st;

    cin >> n;
    while (n--) {
        cin >> num;
        st.push(num);
    }

    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    return 0;
}
