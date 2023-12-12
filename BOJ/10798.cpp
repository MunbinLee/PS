#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> board;
    string line;

    while (cin >> line) {
        board.emplace_back(line);
    }

    for (int i = 0; i < 15; i++) {
        for (auto &s: board) {
            if (i >= s.size()) continue;
            cout << s[i];
        }
    }

    return 0;
}
