#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        printf("'%c'\n", s[i]);
    }
    return 0;
}
