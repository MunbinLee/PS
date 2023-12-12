#include <iostream>
#include <array>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    array<array<bool, 100>, 100> isFilled{};
    int numFilled = 0;

    int numPaper;
    cin >> numPaper;

    while (numPaper--) {
        int x, y;
        cin >> x >> y;
        for (int i = x; i < x + 10; i++) {
            for (int j = y; j < y + 10; j++) {
                if (isFilled[i][j]) continue;
                isFilled[i][j] = true;
                numFilled++;
            }
        }
    }

    cout << numFilled;

    return 0;
}
