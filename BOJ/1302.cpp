#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> counts;

    int N;
    cin >> N;

    while (N--) {
        string book;
        cin >> book;

        counts[book]++;
    }

    int maxCount = -1;
    string answer;

    for (auto [book, count]: counts) {
        if (count > maxCount) {
            maxCount = count;
            answer = book;
        }
    }

    cout << answer;

    return 0;
}
