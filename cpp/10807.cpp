#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    int a;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr[i] = a;
    }

    int v;
    cin >> v;
    int cnt = 0;
    for (int i : arr) {
        if (i == v) cnt++;
    }
    cout << cnt;
    return 0;
}
