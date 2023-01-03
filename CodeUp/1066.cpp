#include <iostream>

using namespace std;

void check(int n) {
    if (n % 2) cout << "odd";
    else cout << "even";
    cout << '\n';
}

int main() {
    int arr[3];
    for (int i = 0; i < 3; i++) cin >> arr[i];
    for (int i = 0; i < 3; i++) check(arr[i]);
    return 0;
}
