#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    while (getline(cin, s)) {
        cout << s << '\n';
    }
    return 0;
}
