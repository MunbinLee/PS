#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int arr[26]{};

    for (char c : s) {
        if (c > 'Z') c -= 'a';
        else c -= 'A';
        arr[c]++;
    }

    int res;
    int max = 0;
    bool multi = false;

    for (int i = 0; i < 26; i++) {
        if (arr[i] > max) {
            res = i;
            max = arr[i];
            multi = false;
        } else if (arr[i] == max) {
            multi = true;
        }
    }

    if (multi) cout << '?';
    else cout << (char) (res + 'A');
    return 0;
}
