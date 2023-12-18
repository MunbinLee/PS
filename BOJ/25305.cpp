#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, k;
    cin >> N >> k;
    vector<int> X(N);

    for (int &x: X) {
        cin >> x;
    }

    sort(X.begin(), X.end(), greater<>());

    cout << X[k - 1];

    return 0;
}
