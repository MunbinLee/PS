#include <iostream>

using namespace std;

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        REP(j, n - i) cout << ' ';
        REP(j, i) cout << '*';
        cout << '\n';
    }
    return 0;
}
