#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> v(N);
    iota(v.begin(), v.end(), 1);

    int index = K - 1;

    cout << '<';

    while (--N) {
        cout << v[index] << ", ";
        v.erase(v.begin() + index);

        index += K - 1;
        index %= (int) v.size();
    }

    cout << v[0] << '>';

    return 0;
}
