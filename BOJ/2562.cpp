#include <iostream>
#include <array>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    array<int, 9> arr{};
    int mx = -1;
    int idx = -1;

    for (int i = 0; i < 9; i++) {
        cin >> arr[i];

        if (arr[i] > mx) {
            mx = arr[i];
            idx = i;
        }
    }

    cout << mx << '\n' << idx + 1;

    return 0;
}