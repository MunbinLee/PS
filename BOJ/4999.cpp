#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;
    string res;

    if (s1.size() >= s2.size()) res = "go";
    else res = "no";

    cout << res;
    return 0;
}
