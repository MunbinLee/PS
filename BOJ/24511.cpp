#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> isStack(N);
    vector<queue<int>> queues(N);
    vector<stack<int>> stacks(N);

    for (int i = 0; i < N; i++) {
        cin >> isStack[i];
    }

    for (int i = 0; i < N; i++) {
        int b;
        cin >> b;

        if (isStack[i]) {
            stacks[i].emplace(b);
            continue;
        }

        queues[i].emplace(b);
    }

    int M;
    cin >> M;

    while (M--) {
        int x;
        cin >> x;

        for (int i = 0; i < N; i++) {
            if (isStack[i]) {
                stacks[i].emplace(x);
                x = stacks[i].top();
                stacks[i].pop();
                continue;
            }

            queues[i].emplace(x);
            x = queues[i].front();
            queues[i].pop();
        }

        cout << x << ' ';
    }

    return 0;
}
