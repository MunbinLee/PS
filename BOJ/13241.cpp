#include <iostream>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long A, B;
    cin >> A >> B;

    cout << lcm(A, B);

    return 0;
}
