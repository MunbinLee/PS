#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    
    int V;
    cin >> V;
    
    vector<vector<pair<int, int>>> edges(V + 1);
    
    for (int i = 0; i < V; i++) {
        int begin;
        cin >> begin;
        
        int end;
        cin >> end;
        
        while (end != -1) {
            int dist;
            cin >> dist;
            
            edges[begin].emplace_back(end, dist);
            
            cin >> end;
        }
    }
    
    auto bfs = [&](int begin) {
        vector<bool> visited(V + 1);
        visited[begin] = true;
        queue<pair<int, int>> q;
        q.emplace(begin, 0);
        int maxCost = -1;
        int furthestVertex = -1;
        
        while (!q.empty()) {
            auto [cur, cost] = q.front();
            q.pop();
            
            for (auto [next, nDist]: edges[cur]) {
                if (visited[next]) {
                    continue;
                }
                
                visited[next] = true;
                int nCost = cost + nDist;
                q.emplace(next, nCost);
                
                if (nCost > maxCost) {
                    maxCost = nCost;
                    furthestVertex = next;
                }
            }
        }
        
        return vector {furthestVertex, maxCost};
    };
    
    cout << bfs(bfs(1)[0])[1];
    
    return 0;
}
