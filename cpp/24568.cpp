#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, s;
    cin >> r >> s;

    cout << r * 8 + s * 3 - 28;
    return 0;
}
