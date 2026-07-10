#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
 
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
 
    int x, y;
    cin >> x >> y;
    x--; y--;
 
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int,int>> q;
    dist[x][y] = 0;
    q.push({x, y});
 
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
 
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                grid[nx][ny] == '.' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j];
            if (j < m - 1) cout << " ";
        }
        cout << "\n";
    }
 
    return 0;
}
