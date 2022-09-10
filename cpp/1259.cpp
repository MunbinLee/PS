#include <iostream>
#include <algorithm>

using namespace std;

string chk(const string &s) {
    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    if (s == tmp) return "yes";
    return "no";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    while (s != "0") {
        cout << chk(s) << '\n';
        cin >> s;
    }
    return 0;
}
