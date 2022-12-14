#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;

    while (c--) {
        int n;
        cin >> n;
        vector<int> v(n);
        double sum = 0;
        for (int &i : v) {
            cin >> i;
            sum += i;
        }
        double cnt = 0;
        double avg = sum / n;
        for (int i : v) {
            if (i > avg) cnt++;
        }
        cnt *= 100.0 / n;
        printf("%.3lf%\n", cnt);
    }
    return 0;
}
