#include <iostream>

using namespace std;

int isPalindrome(string &word) {
    int lo = 0;
    int hi = word.size() - 1;

    while (lo < hi) {
        if (word[lo] != word[hi]) return 0;
        lo++;
        hi--;
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string word;
    cin >> word;

    cout << isPalindrome(word);

    return 0;
}
