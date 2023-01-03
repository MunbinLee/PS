#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    while (n--) {
        int a;
        cin >> a;
        if (a < x) cout << a << ' ';
    }
    return 0;
}
