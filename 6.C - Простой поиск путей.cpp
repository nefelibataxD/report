#include <iostream>
#include <vector>
using namespace std;
 
int n, m, u, v;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> path;
 
bool dfs(int cur) {
    visited[cur] = true;
    path.push_back(cur);
    if (cur == v) return true;
    for (int next : adj[cur]) {
        if (!visited[next]) {
            if (dfs(next)) return true;
        }
    }
    path.pop_back();
    return false;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >> m >> u >> v;
 
    adj.assign(n + 1, {});
    visited.assign(n + 1, false);
 
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    if (dfs(u)) {
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << " ";
        }
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
 
    return 0;
}
