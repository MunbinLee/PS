#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N * N);

    for (int &num: v) {
        cin >> num;
    }

    sort(v.rbegin(), v.rend());

    cout << v[N - 1];

    return 0;
}
