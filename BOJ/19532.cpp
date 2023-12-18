#include <iostream>

using namespace std;

int a, b, c, d, e, f;

void solve() {
    for (int x = -999; x <= 999; x++) {
        for (int y = -999; y <= 999; y++) {
            if (a * x + b * y != c) continue;
            if (d * x + e * y != f) continue;

            cout << x << ' ' << y;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> c >> d >> e >> f;

    solve();

    return 0;
}
