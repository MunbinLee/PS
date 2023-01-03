#include <iostream>

using namespace std;

int main() {
    int n, num, mn;
    cin >> n;

    while (n--) {
        cin >> num;
        mn = min(mn, num);
    }
    cout << mn;
    return 0;
}
