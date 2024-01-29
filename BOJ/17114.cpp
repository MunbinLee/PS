#include <iostream>
#include <array>
#include <numeric>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    array<int, 11> sizes; // NOLINT

    for (int &size: sizes) {
        cin >> size;
    }

    auto encrypt = [&](array<int, 11> &arr) {
        int answer = 0;
        int coefficient = 1;

        for (int i = 0; i < 11; i++) {
            answer += arr[i] * coefficient;
            coefficient *= sizes[i];
        }

        return answer;
    };

    int totalSize = accumulate(sizes.begin(), sizes.end(), 1, multiplies<>());
    vector<int> board(totalSize);
    queue<int> q;
    int unripe = 0;

    for (int i = 0; i < totalSize; i++) {
        cin >> board[i];

        if (board[i] == 0) {
            unripe++;
        }

        if (board[i] == 1) {
            q.emplace(i);
        }
    }

    auto decrypt = [&](int x) {
        array<int, 11> answer; // NOLINT
        int divisor = totalSize;

        for (int i = 10; i >= 0; i--) {
            divisor /= sizes[i];
            answer[i] = x / divisor;
            x %= divisor;
        }

        return answer;
    };

    if (unripe == 0) {
        cout << '0';
        goto EXIT;
    }

    while (!q.empty()) {
        int cur = q.front();
        auto positions = decrypt(cur);
        q.pop();

        for (int i = 0; i < 11; i++) {
            int &position = positions[i];

            position++;
            if (position < sizes[i]) {
                int next = encrypt(positions);

                if (board[next] == 0) {
                    board[next] = board[cur] + 1;
                    q.emplace(next);
                    unripe--;
                }
            }
            position--;

            position--;
            if (position >= 0) {
                int next = encrypt(positions);

                if (board[next] == 0) {
                    board[next] = board[cur] + 1;
                    q.emplace(next);
                    unripe--;
                }
            }
            position++;

            if (unripe == 0) {
                cout << board[cur];
                goto EXIT;
            }
        }
    }

    cout << "-1";

    EXIT:
    return 0;
}
