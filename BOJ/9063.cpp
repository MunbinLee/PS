#include <iostream>

using namespace std;

constexpr int INF = 987654321;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int minX = INF;
    int maxX = -INF;
    int minY = INF;
    int maxY = -INF;

    while (N--) {
        int x, y;
        cin >> x >> y;

        minX = min(minX, x);
        maxX = max(maxX, x);
        minY = min(minY, y);
        maxY = max(maxY, y);
    }

    cout << (maxX - minX) * (maxY - minY);

    return 0;
}
