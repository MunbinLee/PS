#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> ans(n);

    for (int &i : v) {
        cin >> i;
    }

    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && v[i] >= st.top()) st.pop();
        if (st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        st.push(v[i]);
    }

    for (int i : ans) {
        cout << i << " ";
    }
    return 0;
}
