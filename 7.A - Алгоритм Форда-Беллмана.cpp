#include <iostream>
#include <vector>
#include <limits>
 
using namespace std;
 
const long long INF = 1e18;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m, s;
    cin >> n >> m >> s;
    s--;
 
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        graph[u].emplace_back(v, w);
    }
 
    vector<long long> dist(n, INF);
    dist[s] = 0;
 
    for (int i = 0; i < n - 1; ++i) {
        bool updated = false;
        for (int u = 0; u < n; ++u) {
            if (dist[u] == INF) continue;
            for (auto& edge : graph[u]) {
                int v = edge.first;
                int w = edge.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    updated = true;
                }
            }
        }
        if (!updated) break;
    }
 
    bool has_negative_cycle = false;
    for (int u = 0; u < n; ++u) {
        if (dist[u] == INF) continue;
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                has_negative_cycle = true;
                break;
            }
        }
        if (has_negative_cycle) break;
    }
 
    if (has_negative_cycle) {
        cout << "Negative cycle\n";
    } else {
        for (int i = 0; i < n; ++i) {
            if (dist[i] == INF) {
                cout << "inf ";
            } else {
                cout << dist[i] << " ";
            }
        }
        cout << "\n";
    }
 
    return 0;
}
