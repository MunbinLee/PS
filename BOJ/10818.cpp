#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int mn = 1000000;
    int mx = -1000000;

    while (n--) {
        int tmp;
        cin >> tmp;
        mn = min(mn, tmp);
        mx = max(mx, tmp);
    }

    cout << mn << ' ' << mx;
    return 0;
}
