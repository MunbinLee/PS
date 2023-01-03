#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c, mx = 0;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            int n;
            cin >> n;
            if (n > mx) {
                mx = n;
                r = i;
                c = j;
            }
        }
    }
    cout << mx << '\n' << r << ' ' << c;
    return 0;
}
