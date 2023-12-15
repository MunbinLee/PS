#include <iostream>
#include <vector>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    vector<long> tree(N * 2);

    for (int i = 0; i < N; i++) {
        cin >> tree[N + i];
    }

    for (int i = N - 1; i > 0; i--) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    auto update = [&](int key, long value) {
        key += N;
        tree[key] = value;

        while (key /= 2) {
            tree[key] = tree[key * 2] + tree[key * 2 + 1];
        }
    };

    // [begin, end) 합
    auto sum = [&](int begin, int end) {
        long res = 0;
        begin += N;
        end += N;

        while (begin != end) {
            if (begin % 2) res += tree[begin++];
            if (end % 2) res += tree[--end];
            begin /= 2;
            end /= 2;
        }

        return res;
    };

    for (int i = 0; i < M + K; i++) {
        long a, b, c;
        cin >> a >> b >> c;

        if (a == 1) update(b - 1, c);
        else cout << sum(b - 1, c) << '\n';
    }

    return 0;
}
