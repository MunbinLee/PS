#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    int arr[26];
    fill_n(arr, 26, -1);

    for (int i = 0; i < s.length(); i++) {
        int idx = s[i] - 'a';
        if (arr[idx] == -1) arr[idx] = i;
    }

    for (int i : arr) {
        cout << i << ' ';
    }
    return 0;
}
