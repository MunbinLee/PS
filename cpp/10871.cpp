#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, a;
    cin >> n >> x;

    while (n--) {
        cin >> a;
        if (a < x) cout << a << ' ';
    }
    return 0;
}
