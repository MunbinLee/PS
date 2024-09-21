#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    
    vector<tuple<int, int, int>> edges(M);
    
    for (auto& [A, B, C] : edges) {
        cin >> A >> B >> C;
    }
    
    long INF = 987654321;
    vector<long> dists(N + 1, INF);
    dists[1] = 0;
    
    auto hasNegativeCycle = [&]() {
        for (int i = 0; i < N - 1; i++) {
            for (auto [a, b, c] : edges) {
                if (dists[a] == INF || dists[a] + c >= dists[b]) {
                    continue;
                }
                
                dists[b] = dists[a] + c;
            }
        }
        
        for (auto [a, b, c] : edges) {
            if (dists[a] == INF) {
                continue;
            }
            
            if (dists[b] > dists[a] + c) {
                return true;
            }
        }
        
        return false;
    };

    if (hasNegativeCycle()) {
        cout << "-1";
        return 0;
    }
    
    for (int i = 2; i <= N; i++) {
        if (dists[i] == INF) {
            dists[i] = -1;
        }
        
        cout << dists[i] << '\n';
    }
    
    return 0;
}
