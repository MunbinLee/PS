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
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int X;
            cin >> X;

            deq.emplace_front(X);

            continue;
        }

        if (cmd == 2) {
            int X;
            cin >> X;

            deq.emplace_back(X);

            continue;
        }

        if (cmd == 3) {
            if (deq.empty()) {
                cout << "-1\n";
                continue;
            }

            cout << deq.front() << '\n';
            deq.pop_front();

            continue;
        }

        if (cmd == 4) {
            if (deq.empty()) {
                cout << "-1\n";
                continue;
            }

            cout << deq.back() << '\n';
            deq.pop_back();

            continue;
        }

        if (cmd == 5) {
            cout << deq.size()<<'\n';

            continue;
        }

        if (cmd == 6) {
            int res = deq.empty();
            cout << res << '\n';

            continue;
        }

        if (cmd == 7) {
            if (deq.empty()) {
                cout << "-1\n";
                continue;
            }

            cout << deq.front() << '\n';

            continue;
        }

        if (cmd == 8) {
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
