#include <iostream>
#include <vector>

using namespace std;

#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));

    REP(i, 2) REP(j, n) REP(k, m) {
                int tmp;
                cin >> tmp;
                v[j][k] += tmp;
            }

    REP(i, n) {
        REP(j, m) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
