#include <iostream>
#include <algorithm>

using namespace std;

int flip(string s) {
    reverse(s.begin(), s.end());
    return stoi(s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    cout << max(flip(a), flip(b));
    return 0;
}
