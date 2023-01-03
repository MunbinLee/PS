#include <iostream>

using namespace std;

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int mx = 0;
    int res = -1;

    REP(i, 9) {
        int n;
        cin >> n;
        if (n > mx) {
            mx = n;
            res = i;
        }
    }

    cout << mx << '\n' << res + 1;
    return 0;
}
