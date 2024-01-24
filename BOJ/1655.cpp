#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<int> lessPq;
    priority_queue<int, vector<int>, greater<>> greaterPq;

    auto emplace = [&](int x) {
        if (lessPq.empty()) {
            lessPq.emplace(x);
            return;
        }

        if (greaterPq.empty()) {
            int y = lessPq.top();
            lessPq.pop();

            if (x > y) swap(x, y);

            lessPq.emplace(x);
            greaterPq.emplace(y);
            return;
        }

        if (lessPq.size() == 1) {
            if (x > greaterPq.top()) {
                lessPq.emplace(greaterPq.top());
                greaterPq.pop();
                greaterPq.emplace(x);
                return;
            }

            lessPq.emplace(x);
            return;
        }

        if (greaterPq.size() == 1) {
            if (x < lessPq.top()) {
                greaterPq.emplace(lessPq.top());
                lessPq.pop();
                lessPq.emplace(x);
                return;
            }

            greaterPq.emplace(x);
            return;
        }

        if (lessPq.size() == greaterPq.size()) {
            if (x > greaterPq.top()) {
                lessPq.emplace(greaterPq.top());
                greaterPq.pop();
                greaterPq.emplace(x);
                return;
            }

            lessPq.emplace(x);
            return;
        }

        if (x < lessPq.top()) {
            greaterPq.emplace(lessPq.top());
            lessPq.pop();
            lessPq.emplace(x);
            return;
        }

        greaterPq.emplace(x);
    };

    auto getMiddleValue = [&]() {
        if (greaterPq.empty()) return lessPq.top();

        return lessPq.top();
    };

    while (N--) {
        int num;
        cin >> num;

        emplace(num);
        cout << getMiddleValue() << '\n';
    }

    return 0;
}
