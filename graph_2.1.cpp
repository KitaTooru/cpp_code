#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

#define vNum 100

struct edge
{
    int v;
    int w;
    edge(int v1 = 0, int w1 = 0) : v(v1), w(w1) {}
};

void add_edge(vector<edge> g[vNum], int u, int v, int w)
{
    g[u].push_back(edge(v, w));
}

bool topological_sort(vector<edge> g[vNum], int n, int tsort[vNum])
{
    int ind[vNum] = {0};
    for (int i = 1; i <= n; i++)
    {
        for (const auto &e : g[i])
        {
            ind[e.v]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
        {
            q.push(i);
        }
    }
    int cnt = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        tsort[cnt++] = u;
        for (const auto &e : g[u])
        {
            ind[e.v]--;
            if (ind[e.v] == 0)
            {
                q.push(e.v);
            }
        }
    }
    return cnt == n;
}

void critical_path(vector<edge> g[vNum], int n, int start_node)
{
    vector<edge> cp[vNum];
    int tsort[vNum], ve[vNum] = {0}, vl[vNum];

    if (!topological_sort(g, n, tsort))
    {
        cout << "图g存在环路！" << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        ve[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int u = tsort[i];
        for (const auto &e : g[u])
        {
            ve[e.v] = max(ve[e.v], ve[u] + e.w);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        vl[i] = ve[tsort[n - 1]];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int u = tsort[i];
        for (const auto &e : g[u])
        {
            vl[u] = min(vl[u], vl[e.v] - e.w);
        }
    }

    cout << "事件 V3 的最早开始时间为: " << ve[3] << " 天" << endl;

    cout << "关键路径为: ";
    for (int i = 1; i <= n; i++)
    {
        for (const auto &e : g[i])
        {
            int ae = ve[i];
            int al = vl[e.v] - e.w;
            if (ae == al)
            {
                cout << "V" << i << " -> V" << e.v << " ";
            }
        }
    }
    cout << endl;
}

int main()
{
    vector<edge> g[vNum];
    int n = 6;

    add_edge(g, 1, 2, 6);
    add_edge(g, 1, 3, 4);
    add_edge(g, 2, 3, 7);
    add_edge(g, 2, 5, 9);
    add_edge(g, 3, 4, 8);
    add_edge(g, 3, 6, 11);
    add_edge(g, 4, 6, 21);
    add_edge(g, 5, 6, 3);

    critical_path(g, n, 1);

    return 0;
}
