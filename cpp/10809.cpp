#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;

    int arr[26];
    fill_n(arr, 26, -1);

    for (int i = 0; i < s.size(); i++) {
        int idx = s[i] - 'a';
        if (arr[idx] == -1) arr[idx] = i;
    }

    for (int i : arr) {
        cout << i << ' ';
    }
    return 0;
}
