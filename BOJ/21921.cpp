#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X;
    cin >> N >> X;

    vector<int> visitors(N);

    for (int &visitor: visitors) {
        cin >> visitor;
    }

    int cur = 0;

    for (int i = 0; i < X; i++) {
        cur += visitors[i];
    }

    int lo = 0;
    int hi = X;
    int maxVisitors = 0;
    int period = -1;

    while (true) {
        if (cur == maxVisitors) {
            period++;
        } else if (cur > maxVisitors) {
            maxVisitors = cur;
            period = 1;
        }

        if (hi >= N) break;

        cur -= visitors[lo];
        cur += visitors[hi];
        lo++;
        hi++;
    }

    if (maxVisitors == 0) {
        cout << "SAD";
        return 0;
    }

    cout << maxVisitors << '\n' << period;

    return 0;
}
