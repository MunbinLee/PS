#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> vec(n);

    for (auto &[h, o]: vec) {
        cin >> h >> o;

        if (h > o) swap(h, o);
    }

    int d;
    cin >> d;

    vector<pair<int, int>> people;
    people.reserve(n);

    for (auto [h, o]: vec) {
        if (o - h > d) continue;

        people.emplace_back(h, o);
    }

    sort(people.begin(), people.end());

    int lo = 0;
    int answer = 0;

    while (true) {
        if (lo >= people.size()) break;

        int nlo = lo;

        while (true) {
            if (nlo >= people.size()) break;
            if (people[nlo].first != people[lo].first) break;

            nlo++;
        }

        int hi = lo;

        while (true) {
            if (hi >= people.size()) break;
            if (people[hi].second > people[lo].first + d) break;

            hi++;
        }

        answer = max(answer, hi - lo);
        lo = nlo;
    }

    cout << answer;

    return 0;
}
