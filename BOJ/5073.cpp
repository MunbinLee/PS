#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

array<int, 3> lines;

void input() {
    for (int &line: lines) {
        cin >> line;
    }

    sort(lines.begin(), lines.end());
}

string solve() {
    if (lines[0] + lines[1] <= lines[2]) return "Invalid";

    if (lines[0] == lines[2]) return "Equilateral";

    if (lines[0] == lines[1] || lines[1] == lines[2]) return "Isosceles";

    return "Scalene";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (input(); lines[0] != 0; input()) {
        cout << solve() << '\n';
    }

    return 0;
}
