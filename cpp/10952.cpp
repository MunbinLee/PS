#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;

    while (true) {
        cin >> a >> b;
        if (a == 0) return 0;
        cout << a + b << '\n';
    }
}
