#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ur, tr, uo, to;
    cin >> ur >> tr >> uo >> to;

    cout << 56 * ur + 24 * tr + 14 * uo + 6 * to;
    return 0;
}
