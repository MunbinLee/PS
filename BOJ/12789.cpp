#include <iostream>
#include <stack>

using namespace std;

bool solve() {
    stack<int> st;

    int N;
    cin >> N;

    int line = 1;

    while (N--) {
        int num;
        cin >> num;

        if (num == line) {
            line++;

            while (!st.empty() && st.top() == line) {
                st.pop();
                line++;
            }

            continue;
        }

        st.emplace(num);
    }

    return st.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string answer = solve() ? "Nice" : "Sad";

    cout << answer;

    return 0;
}
