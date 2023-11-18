#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> heights(N);

    for (int &height: heights) {
        cin >> height;
    }

    vector<int> inversedPrefixSum(N);
    inversedPrefixSum[0] = heights[0];

    for (int i = 1; i < N; i++) {
        inversedPrefixSum[i] = heights[i] - heights[i - 1];
    }

    while (M--) {
        int a, b, k;
        cin >> a >> b >> k;
        inversedPrefixSum[a - 1] += k;
        if (b != N) inversedPrefixSum[b] -= k;
    }

    int height = 0;

    for (int diff: inversedPrefixSum) {
        height += diff;
        cout << height << ' ';
    }

    return 0;
}
