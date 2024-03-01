#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;

    int chocolate = 1 << int(ceil(log2(K)));
    cout << chocolate << ' ';

    int count = 0;

    while (K) {
        if (K == chocolate) {
            break;
        }

        chocolate /= 2;

        if (K >= chocolate) {
            K -= chocolate;
        }

        count++;
    }

    cout << count;

    return 0;
}
