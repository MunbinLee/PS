#include <iostream>
#include <vector>

using namespace std;

int main() {
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

    auto update = [&](int begin, int end, long value) {

    };

    // [begin, end) 합
    auto sum = [&](int begin, int end) {
        return 1;
    };

    for (int i = 0; i < M + K; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            long d;
            cin >> d;
            update(b, c, d);
        } else {
            cout << sum(b - 1, c) << '\n';
        }
    }

    return 0;
}
