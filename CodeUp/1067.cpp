#include <iostream>

using namespace std;

void check(int n) {
    if (n % 2) cout << "odd";
    else cout << "even";
    cout << '\n';
}

int main() {
    int n;
    cin >> n;

    if (n > 0) cout << "plus";
    else cout << "minus";
    cout << '\n';

    if (n % 2) cout << "odd";
    else cout << "even";
    return 0;
}
