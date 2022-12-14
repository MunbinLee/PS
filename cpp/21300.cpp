#include <iostream>

using namespace std;

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;

    REP(i, 6) {
        int tmp;
        cin >> tmp;
        n += tmp;
    }

    cout << n * 5;
    return 0;
}
