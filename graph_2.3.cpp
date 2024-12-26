#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define vNum 100

struct edge
{
    int v;
    int w;
    edge(int v1 = 0, int w1 = 0) : v(v1), w(w1) {}
};

struct node
{
    int u, v, d;
    node(int u1, int v1, int d1) : u(u1), v(v1), d(d1) {}
    bool operator<(const node &n1) const
    {
        return d > n1.d;
    }
};

void Dijkstra(vector<edge> g[vNum], int n, int st, int d[vNum], int p[vNum])
{
    memset(d, 0x3f, sizeof(int) * vNum);
    memset(p, -1, sizeof(int) * vNum);
    int vis[vNum] = {0};
    priority_queue<node> pq;
    d[st] = 0;
    p[st] = st;
    pq.push(node(st, st, 0));

    while (!pq.empty())
    {
        node tmp = pq.top();
        pq.pop();
        int u = tmp.v;
        if (vis[u])
            continue;
        vis[u] = 1;

        for (int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i].v;
            int w = g[u][i].w;
            if (!vis[v] && d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                p[v] = u;
                pq.push(node(u, v, d[v]));
            }
        }
    }
}

void getPath(int p[vNum], int v)
{
    if (p[v] == v)
    {
        cout << v << ' ';
        return;
    }
    getPath(p, p[v]);
    cout << v << ' ';
}

int main()
{
    int n = 6;
    vector<edge> g[vNum];

    g[1].push_back(edge(2, 15));
    g[1].push_back(edge(3, 10));
    g[1].push_back(edge(5, 45));

    g[2].push_back(edge(5, 15));
    g[2].push_back(edge(4, 20));

    g[3].push_back(edge(2, 10));
    g[3].push_back(edge(4, 60));

    g[4].push_back(edge(6, 20));

    g[5].push_back(edge(6, 15));

    int d[vNum], p[vNum];

    Dijkstra(g, n, 1, d, p);

    for (int i = 1; i <= n; i++)
    {
        cout << "顶点1到顶点" << i << "的最短距离：" << d[i] << endl;
        cout << "路径：";
        getPath(p, i);
        cout << endl;
    }

    return 0;
}
