#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> vec(n);

    for (int &i : vec) cin >> i;

    int v;
    cin >> v;
    int cnt = 0;

    for (int i : vec) {
        if (i == v) cnt++;
    }

    cout << cnt;
    return 0;
}
