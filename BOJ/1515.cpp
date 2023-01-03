#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = 1;
    int idx = -1;
    for (char c : s) {
        while (true) {
            idx++;
            if (idx >= to_string(n).size()) {
                idx = 0;
                n++;
            }
            if (c == to_string(n)[idx]) {
                break;
            }
        }
    }
    cout << n;
    return 0;
}
