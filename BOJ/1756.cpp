#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int D, N;
    cin >> D >> N;

    vector<int> ovens(D);

    for (int &oven: ovens) {
        cin >> oven;
    }

    vector<int> minOven(D);
    int mn = 1087654321;

    for (int i = 0; i < D; i++) {
        mn = min(mn, ovens[i]);
        minOven[i] = mn;
    }

// value 이상인 최후의 인덱스를 반환
auto binarySearch = [&](int hi, int value) {
    int lo = 0;
    int answer = -1;

    while (lo <= hi) {
        int md = (lo + hi) / 2;

        if (minOven[md] >= value) {
            answer = md;
            lo = md + 1;
        } else {
            hi = md - 1;
        }
    }

    return answer;
};

    int lastOven = D - 1;

    while (N--) {
        int pizza;
        cin >> pizza;

        int pos = binarySearch(lastOven, pizza);
        lastOven = pos - 1;
    }

    cout << lastOven + 2;

    return 0;
}
