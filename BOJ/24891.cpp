#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, N;
    cin >> L >> N;

    vector<string> words(N);

    for (auto &word: words) {
        cin >> word;
    }

    queue<tuple<int, int, vector<vector<char>>>> q;
    vector<vector<char>> init(L, vector<char>(L));
    q.emplace(0, 0, init);

    vector<vector<char>> answer = {{'Z' + 1}};

    while (!q.empty()) {
        auto [index, mask, cur] = q.front();
        q.pop();

        auto isValid = [&](int i) {
            for (int j = 0; j < L; j++) {
                if (!cur[index][j]) continue;
                if (cur[index][j] != words[i][j]) return false;
            }

            return true;
        };

        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) continue;
            if (!isValid(i)) continue;

            auto next = cur;

            for (int j = 0; j < L; j++) {
                next[index][j] = words[i][j];
                next[j][index] = words[i][j];
            }

            if (index + 1 == L) {
                answer = min(answer, next);
                continue;
            }

            q.emplace(index + 1, mask | (1 << i), next);
        }
    }

    if (answer.size() == 1) {
        cout << "NONE";
        return 0;
    }

    for (auto &word: answer) {
        for (char ch: word) {
            cout << ch;
        }
        cout << '\n';
    }

    return 0;
}