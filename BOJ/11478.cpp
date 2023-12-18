#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, bool> visited;

    string S;
    cin >> S;

    for (int i = 0; i < S.size(); i++) {
        for (int j = i; j < S.size(); j++) {
            visited[S.substr(i, j - i + 1)] = true;
        }
    }

    cout << visited.size();

    return 0;
}
