#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c;
    cin >> a >> b >> c;

    cout << (b - c) / a;
    return 0;
}
