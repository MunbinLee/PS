#include <iostream>
#include <vector>

using namespace std;

vector<int> base;
vector<vector<bool>> path, visited;

void dfs(int x) {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    cin >> n >> m >> s;

    base = vector<int>(n);
    for (int &i : base) cin >> i;

    while (m--) {
        int a, b;
        cin >> a >> b;
        path[a][b] = true;
        path[b][a] = true;
    }
    return 0;
}
