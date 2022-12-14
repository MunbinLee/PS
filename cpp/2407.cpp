#include <iostream>

using namespace std;

long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    cout << factorial(n) << ' ' << factorial(n - m) << ' ' << factorial(m);
    return 0;
}
