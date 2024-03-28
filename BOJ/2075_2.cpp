#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<>> pq;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        pq.emplace(num);
    }

    for (int i = 0; i < N * (N - 1); i++) {
        int num;
        cin >> num;
        pq.emplace(num);
        pq.pop();
    }

    cout << pq.top();

    return 0;
}
