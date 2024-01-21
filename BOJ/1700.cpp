#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> items(K);

    for (int &item: items) {
        cin >> item;
    }

    vector<queue<int>> usages(K + 1);

    for (int time = 0; time < K; time++) {
        int item = items[time];
        usages[item].emplace(time);
    }

    const int INF = 987654321;

    auto getNextUsageTime = [&](int item, int curTime) {
        auto &usage = usages[item];

        while (!usage.empty()) {
            int usageTime = usage.front();

            if (usageTime <= curTime) {
                usage.pop();
                continue;
            }

            return usageTime;
        }

        return INF;
    };

    unordered_set<int> connected;

    auto getItemToRemove = [&](int curTime) {
        int maxNextUsageTime = -1;
        int itemToRemove = -1;

        for (auto item: connected) {
            int nextUsageTime = getNextUsageTime(item, curTime);

            if (nextUsageTime <= maxNextUsageTime) continue;

            maxNextUsageTime = nextUsageTime;
            itemToRemove = item;
        }

        return itemToRemove;
    };

    int answer = 0;

    for (int time = 0; time < K; time++) {
        int curItem = items[time];

        if (connected.contains(curItem)) continue;

        if (connected.size() < N) {
            connected.insert(curItem);
            continue;
        }

        int itemToRemove = getItemToRemove(time);

        connected.erase(itemToRemove);
        connected.insert(curItem);
        answer++;
    }

    cout << answer;

    return 0;
}
