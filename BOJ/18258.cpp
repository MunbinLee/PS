#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<int> deq;

    int N;
    cin >> N;

    while (N--) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int X;
            cin >> X;

            deq.emplace_back(X);

            continue;
        }

        if (cmd == "pop") {
            if (deq.empty()) {
                cout << "-1\n";
                continue;
            }

            cout << deq.front() << '\n';
            deq.pop_front();

            continue;
        }

        if (cmd == "size") {
            cout << deq.size() << '\n';

            continue;
        }

        if (cmd == "empty") {
            int res = deq.empty();
            cout << res << '\n';

            continue;
        }

        if (cmd == "front") {
            if (deq.empty()) {
                cout << "-1\n";
                continue;
            }

            cout << deq.front() << '\n';

            continue;
        }

        if (cmd == "back") {
            if (deq.empty()) {
                cout << "-1\n";
                continue;
            }

            cout << deq.back() << '\n';

            continue;
        }
    }

    return 0;
}
