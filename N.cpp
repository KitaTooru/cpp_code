#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge {
    int to, toll;
};

struct Node {
    int point, cost;
    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

void dijkstra(int N, int S, vector<vector<Edge>>& graph, vector<int>& dist) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    dist[S] = 0;
    pq.push({S, 0});
    
    while (!pq.empty()) {
        int u = pq.top().point;
        int d = pq.top().cost;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& edge : graph[u]) {
            int v = edge.to;
            int toll = edge.toll;
            int new_cost = dist[u] + 12 + toll;
            
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({v, dist[v]});
            }
        }
    }
}

int main() {
    int k;
    cin >> k;
    
    while (k--) {
        int N, R, S, D;
        cin >> N >> R >> S >> D;
        
        vector<vector<Edge>> graph(N + 1);
        vector<int> dist(N + 1, INT_MAX);
        
        for (int i = 0; i < R; ++i) {
            int U, V, T;
            cin >> U >> V >> T;
            graph[U].push_back({V, T});
            graph[V].push_back({U, T});
        }
        
        dijkstra(N, S, graph, dist);
        
        cout << dist[D] << endl;
    }
    
    return 0;
}
