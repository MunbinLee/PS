#include <iostream>

using namespace std;

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int r;
        string s;
        cin >> r >> s;
        for (char c : s) {
            REP(i, r) cout << c;
        }
        cout << '\n';
    }
    return 0;
}
