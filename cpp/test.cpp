#include <iostream>
#include <stack>

using namespace std;

string res;
int cnt = 1;
stack<int> st;

bool write(int n) {
    while (cnt <= n) {
        st.push(cnt);
        cnt++;
        res += "+\n";
    }
    if (st.top() == n) {
        st.pop();
        res += "-\n";
        return true;
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        int tmp;
        cin >> tmp;
        if (!write(tmp)) {
            cout << "NO";
            return 0;
        }
    }

    cout << res;
    return 0;
}
