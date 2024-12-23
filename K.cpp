#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

struct Edge {
    int to, weight;
};

vector<Edge> adj[1000];
int dist[1000];

void bfs(int start, int n) {
    fill(dist, dist + n, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const auto& edge : adj[u]) {
            int v = edge.to, w = edge.weight;
            if (dist[v] == -1) {
                dist[v] = dist[u] + w;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        char dir;
        cin >> u >> v >> w >> dir;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    bfs(0, n);
    int farthest = 0;
    for (int i = 0; i < n; ++i) {
        if (dist[i] > dist[farthest]) farthest = i;
    }

    bfs(farthest, n);
    int maxDist = 0;
    for (int i = 0; i < n; ++i) {
        maxDist = max(maxDist, dist[i]);
    }

    cout << maxDist << endl;
    return 0;
}
