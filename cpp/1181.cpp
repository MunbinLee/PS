#include <iostream>
#include <set>

using namespace std;

bool cmp(const string &s1, const string &s2) {
    if (s1.size() == s2.size()) return s1 < s2;
    return s1.size() < s2.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    set<string, decltype(&cmp)> s(cmp);

    while (n--) {
        string tmp;
        cin >> tmp;
        s.insert(tmp);
    }

    for (const string &tmp : s) {
        cout << tmp << '\n';
    }
    return 0;
}
