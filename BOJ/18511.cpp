#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> K;

int dfs(int cur) {
    if (cur > N) return -1;

    int res = cur;

    for (int k: K) {
        res = max(res, dfs(cur * 10 + k));
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int len;
    cin >> N >> len;
    K.resize(len);

    for (int &k: K) {
        cin >> k;
    }

    cout << dfs(0);

    return 0;
}
