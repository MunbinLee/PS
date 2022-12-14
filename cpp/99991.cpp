#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a % b == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
