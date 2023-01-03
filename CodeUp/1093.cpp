#include <iostream>

using namespace std;

int main() {
    int n, num;
    int arr[23]{};

    cin >> n;
    while (n--) {
        cin >> num;
        arr[num - 1]++;
    }

    for (int i: arr) {
        cout << i << ' ';
    }
    return 0;
}
