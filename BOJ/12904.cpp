#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T;
    cin >> S >> T;

    while (S.size() <= T.size()) {
        if (S == T) {
            cout << '1';
            return 0;
        }

        if (T.back() == 'A') {
            T.pop_back();
        } else {
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }

    cout << 0;
    return 0;
}