#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    unordered_map<int, vector<int>> positions;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        positions[A[i]].emplace_back(i);
    }

    auto isGood = [&](int index, int x) {
        for (int j = 0; j < N; j++) {
            if (j == index) continue;

            int target = x - A[j];

            if (!positions.contains(target)) continue;
            if (positions[target].size() == 1 && positions[target][0] == index) continue;
            if (positions[target].size() == 1 && positions[target][0] == j) continue;
            if (positions[target].size() == 2 && positions[target][0] == index && positions[target][1] == j) continue;
            if (positions[target].size() == 2 && positions[target][0] == j && positions[target][1] == index) continue;

            return true;
        }

        return false;
    };

    int answer = 0;

    for (int i = 0; i < N; i++) {
        answer += isGood(i, A[i]);
    }

    cout << answer;

    return 0;
}
