#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define vNum 6
#define INF 9999

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

bool vis[vNum + 1];
vector<edge> g[vNum + 1];
vector<int> t[vNum + 1];

void prim(vector<edge> g[], int n, vector<int> t[])
{
    priority_queue<node> pq;
    int step = n - 1, u, v;
    for (int i = 0; i < g[1].size(); i++)
    {
        edge tmp = g[1][i];
        pq.push(node(1, tmp.v, tmp.w));
    }
    vis[1] = true;
    while (step--)
    {
        node tmp = pq.top();
        pq.pop(), v = tmp.v;
        while (vis[v])
        {
            tmp = pq.top();
            pq.pop(), v = tmp.v;
        }
        u = tmp.u, vis[v] = true;
        t[u].push_back(v);
        t[v].push_back(u);
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

int main()
{
    g[1].push_back(edge(2, 6));
    g[1].push_back(edge(3, 3));
    g[2].push_back(edge(1, 6));
    g[2].push_back(edge(4, 1));
    g[2].push_back(edge(6, 5));
    g[3].push_back(edge(1, 3));
    g[3].push_back(edge(4, 6));
    g[3].push_back(edge(5, 6));
    g[4].push_back(edge(2, 1));
    g[4].push_back(edge(3, 6));
    g[4].push_back(edge(5, 6));
    g[5].push_back(edge(3, 6));
    g[5].push_back(edge(4, 6));
    g[5].push_back(edge(6, 2));
    g[6].push_back(edge(2, 5));
    g[6].push_back(edge(5, 2));

    prim(g, 6, t);

    for (int i = 1; i <= 6; i++)
    {
        for (int v : t[i])
        {
            if (i < v)
            {
                cout << i << " - " << v << endl;
            }
        }
    }

    return 0;
}
