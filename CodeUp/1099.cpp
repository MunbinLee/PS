#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<vector<int>> v(10, (vector<int>(10, 0)));

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> n;
            v[i][j] = n;
        }
    }

    int y = 1;
    int x = 1;
    while (true) {
        if (v[y][x] == 2) {
            v[y][x] = 9;
            break;
        }

        v[y][x] = 9;
        if (x < v[0].size() && v[y][x + 1] != 1) x++;
        else if (y < v.size() && v[y + 1][x] != 1) y++;
        else break;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
