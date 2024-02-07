#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> lines(N);

    for (int &line: lines) {
        cin >> line;
    }

    sort(lines.rbegin(), lines.rend());

    auto solve = [&]() {
        for (int i = 0; i + 2 < N; i++) {
            if (lines[i] >= lines[i + 1] + lines[i + 2]) continue;

            return lines[i] + lines[i + 1] + lines[i + 2];
        }

        return -1;
    };

    cout << solve();

    return 0;
}
