#include <iostream>
#include <vector>
#include <queue>
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
    int u, v, w;
    node(int u1 = 0, int v1 = 0, int w1 = 0) : u(u1), v(v1), w(w1) {}
    bool operator<(node n1) const
    {
        return w > n1.w;
    }
};
bool vis[vNum];

void prim(vector<edge> g[vNum], int n, vector<int> t[vNum])
{
    priority_queue<node> pq;
    int i, step = n - 1, u, v;
    for (i = 0; i < g[1].size(); i++)
    {
        edge tmp = g[1][i];
        pq.push(node(1, tmp.v, tmp.w));
    }
    vis[1] = 1;
    while (step--)
    {
        node tmp = pq.top();
        pq.pop(), v = tmp.v;
        while (vis[v])
        {
            tmp = pq.top();
            pq.pop(), v = tmp.v;
        }
        u = tmp.u, vis[tmp.v] = 1;
        t[v].push_back(u), t[u].push_back(v);
        for (int i = 0; i < g[v].size(); i++)
        {
            edge tmp = g[v][i];
            if (!vis[tmp.v])
            {
                pq.push(node(v, tmp.v, tmp.w));
            }
        }
    }
}