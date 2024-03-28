#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, W;
    cin >> T >> W;

    vector<int> trees(T);

    for (int &tree: trees) {
        cin >> tree;
    }

    int cur = 0;

    while (cur < T && trees[cur] == 1) {
        cur++;
    }

    int prevTree = 1;
    int count = 0;
    vector<int> sortedCounts;

    for (; cur < T; cur++) {
        if (trees[cur] == prevTree) {
            count++;
            continue;
        }

        if (count) {
            sortedCounts.emplace_back(count);
        }

        count = 1;
        prevTree = trees[cur];
    }

    if (count) {
        sortedCounts.emplace_back(count);
    }

    sort(sortedCounts.rbegin(), sortedCounts.rend());

    int answer = T;

    for (int i = 0; i < ((int) sortedCounts.size() - W + 1) / 2; i++) {
        int discount = sortedCounts.back();
        sortedCounts.pop_back();
        answer -= discount;
    }

    cout << answer;

    return 0;
}
