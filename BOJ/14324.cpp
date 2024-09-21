#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int INF = 987654321;
int R, C;
array<int, 4> dr {-1, 0, 1, 0}, dc {0, -1, 0, 1};
vector<vector<int>> board;
vector<tuple<int, int, int>> updates;

int getIncreasedHeight(int r, int c) {
    queue<pair<int, int>> q;
    q.emplace(r, c);
    vector<vector<bool>> visited(R, vector<bool>(C));
    visited[r][c] = true;
    int minHeightAboveArea = INF;
    
    while (!q.empty()) {
        auto [cr, cc] = q.front();
        q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nr = cr + dr[dir];
            int nc = cc + dc[dir];
            
            if (nr == -1 || nr == R || nc == -1 || nc == C || board[nr][nc] < board[r][c]) {
                return 0;
            }
            
            if (visited[nr][nc]) {
                continue;
            }
            
            if (board[nr][nc] == board[r][c]) {
                visited[nr][nc] = true;
                q.emplace(nr, nc);
                continue;
            }
            
            minHeightAboveArea = min(minHeightAboveArea, board[nr][nc]);
        }
    }
    
    if (minHeightAboveArea == INF) {
        return 0;
    }
    
    updates.emplace_back(r, c, minHeightAboveArea);
    
    int answer = minHeightAboveArea - board[r][c];
    return answer;
}

int solve() {
    cin >> R >> C;
    
    board = vector<vector<int>>(R, vector<int>(C));
    
    for (auto& row : board) {
        for (int& cell : row) {
            cin >> cell;
        }
    }
    
    int answer = 0;
    bool loop = true;
    
    while (loop) {
        loop = false;
        updates.clear();
        
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                int increasedHeight = getIncreasedHeight(r, c);
                
                if (increasedHeight > 0) {
                    answer += getIncreasedHeight(r, c);
                    loop = true;
                }
            }
        }
        
        for (auto [r, c, value] : updates) {
            board[r][c] = value;
        }
    }
    
    return answer;
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << '\n';
    }
    
    return 0;
}
