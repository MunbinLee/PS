#include <vector>
#include <iostream>

#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;

int n;
vvi v;

vvi product(vvi a, vvi b) {
    vvi res(n, vi(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = 0;
            for (int k = 0; k < n; k++) {
                res[i][j] += a[i][k] * b[k][j] % 1000;
            }
            res[i][j] %= 1000;
        }
    }
    return res;
}

vvi pow(long long int cnt) {
    if (cnt==1) return v;
    vvi tmp = pow(cnt/2);
    vvi tmp2 = product(tmp, tmp);
    if (cnt%2) return product(tmp2,v);
    return tmp2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int b;
    cin >> n >> b;
    v = vector(n, vi(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            v[i][j] = num;
        }
    }

    vvi res;
    if (b==1) res = v;
    else res = product(pow(b-1),v);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] % 1000 << ' ';
        }
        cout << '\n';
    }
    return 0;
}
