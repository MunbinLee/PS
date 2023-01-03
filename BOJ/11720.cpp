#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    int res = 0;

    for (int i = 0; i < n; i++) {
        res += s[i] - '0';
    }

    cout << res;
    return 0;
}
