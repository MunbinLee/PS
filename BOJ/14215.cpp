#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    array<int, 3> lines; // NOLINT

    for (int &line: lines) {
        cin >> line;
    }

    sort(lines.begin(), lines.end());

    cout << lines[0] + lines[1] + min(lines[2], lines[0] + lines[1] - 1);

    return 0;
}
