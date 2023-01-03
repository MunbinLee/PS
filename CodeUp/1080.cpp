#include <iostream>

using namespace std;

int main() {
    int n;
    int sum = 0;
    cin >> n;

    for (int i = 1;; i++) {
        sum += i;
        if (sum >= n) {
            cout << i;
            return 0;
        }
    }
}
