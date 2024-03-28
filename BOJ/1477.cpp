#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, L;
    cin >> N >> M >> L;

    vector<int> rests(N);

    for (int &rest: rests) {
        cin >> rest;
    }

    sort(rests.begin(), rests.end());

    priority_queue<int> pq;

    for (int i = 1; i < rests.size(); i++) {
        pq.emplace(rests[i] - rests[i - 1]);
    }

    while (M--) {
        int cur = pq.top();
        pq.pop();
        pq.emplace(cur / 2);
        pq.emplace(cur / 2 + cur % 2);
    }

    cout << pq.top();

    return 0;
}
