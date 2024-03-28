#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N), answer(N, -1);

    for (int &num: A) {
        cin >> num;
    }

    stack<int> st;

    for (int i = N - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= A[i]) {
            st.pop();
        }

        if (!st.empty()) {
            answer[i] = st.top();
        }

        st.emplace(A[i]);
    }

    for (int num: answer) {
        cout << num << ' ';
    }

    return 0;
}