#include <iostream>
#include <unordered_set>

using namespace std;

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<int> s;

    REP(i, 10) {
        int tmp;
        cin >> tmp;
        s.insert(tmp % 42);
    }

    cout << s.size();
    return 0;
}
