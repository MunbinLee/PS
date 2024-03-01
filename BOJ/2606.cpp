#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numComputer, numNetwork;
    cin >> numComputer >> numNetwork;

    vector<int> roots(numComputer + 1);
    iota(roots.begin(), roots.end(), 0);

    function<int(int)> find = [&](int x) {
        if (roots[x] == x) return x;

        return roots[x] = find(roots[x]);
    };

    auto merge = [&](int a, int b) {
        a = find(a);
        b = find(b);

        if (a < b) swap(a, b);

        roots[a] = b;
    };

    while (numNetwork--) {
        int c1, c2;
        cin >> c1 >> c2;

        merge(c1, c2);
    }

    int answer = 0;

    for (int i = 2; i <= numComputer; i++) {
        answer += (find(i) == 1);
    }

    cout << answer;

    return 0;
}
