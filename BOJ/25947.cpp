#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, b, a;
    cin >> n >> b >> a;

    vector<int> gifts(n);

    for (int &gift: gifts) {
        cin >> gift;
    }

    sort(gifts.begin(), gifts.end());

    int answer = 0;
    int cost = 0;

    while (true) {
        if (answer >= a) {
            cost += gifts[answer - a] / 2;
        }

        cost += gifts[answer] / 2;

        if (cost > b) break;

        answer++;

        if (answer == n) break;
    }

    cout << answer;

    return 0;
}
