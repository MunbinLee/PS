#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> st;

    int N;
    cin >> N;

    while (N--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int x;
            cin >> x;
            st.emplace(x);
        } else if (cmd == 2) {
            if (st.empty()) {
                cout << "-1" <<'\n';
            } else {
                cout << st.top() << '\n';
                st.pop();
            }
        } else if (cmd == 3) {
            cout << st.size() << '\n';
        } else if (cmd == 4) {
            cout << (int) st.empty() << '\n';
        } else {
            if (st.empty()) {
                cout << "-1" <<'\n';
            } else {
                cout << st.top() << '\n';
            }
        }
    }

    return 0;
}
