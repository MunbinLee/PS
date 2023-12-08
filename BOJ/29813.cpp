#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pr = pair<string, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    queue<pr> q;

    for (int i = 0; i < N; i++) {
        string name;
        int id;
        cin >> name >> id;
        q.emplace(name, id % 100 - 1);
    }

    while (q.size() >= 2) {
        auto [name, id] = q.front();
        q.pop();
        for (int i = 0; i < id; i++) {
            auto pass = q.front();
            q.pop();
            q.emplace(pass);
        }
        q.pop();
    }

    cout << q.front().first;

    return 0;
}
