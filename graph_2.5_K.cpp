#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define vNum 100
#define eNum 1000

struct edge
{
    int v;
    int w;
    edge(int v1 = 0, int w1 = 0) : v(v1), w(w1) {}
};

struct node
{
    int u, v, w;
    node(int u1 = 0, int v1 = 0, int w1 = 0) : u(u1), v(v1), w(w1) {}
    bool operator<(node n1) const
    {
        return w < n1.w;
    }
} edges[eNum];

void kruskal(vector<edge> g[vNum], int n, vector<int> t[vNum])
{
    int i, j, cnt = 0, num = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < g[i].size(); j++)
        {
            edge tmp = g[i][j];
            if (i < tmp.v)
            {
                edges[num++] = node(i, tmp.v, tmp.w);
            }
        }
    }
    sort(edges, edges + cnt);
    for (i = 0; i < cnt; i++)
    {
        int u = edges[i].u, v = edges[i].v;
        if (query(u) != query(v))
        {
            merge(u, v);
            t[u].push_back(v);
            t[v].push_back(u);
            if (++num == n - 1)
            {
                break;
            }
        }
    }
}
