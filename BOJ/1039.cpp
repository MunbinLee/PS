#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    queue<pair<int, int>> q;
    q.emplace(N, K);
    int answer = -1;
    int lastCount = K;
    unordered_set<string> visited;

    while (!q.empty()) {
        auto [cur, count] = q.front();
        q.pop();

        if (count == 0) {
            answer = max(answer, cur);
            continue;
        }

        if (count != lastCount) {
            lastCount = count;
            visited.clear();
        }

        string curString = to_string(cur);
        string token = curString + ' ' + to_string(count);

        if (visited.contains(token)) continue;

        visited.emplace(token);

        for (int i = 0; i + 1 < curString.size(); i++) {
            for (int j = i + 1; j < curString.size(); j++) {
                if (i == 0 && curString[j] == '0') continue;

                swap(curString[i], curString[j]);
                q.emplace(stoi(curString), count - 1);
                swap(curString[i], curString[j]);
            }
        }
    }

    cout << answer;

    return 0;
}
