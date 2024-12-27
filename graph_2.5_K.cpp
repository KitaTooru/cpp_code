#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vNum 6
#define eNum 15

struct edge
{
    int u, v, w;
    edge(int u1 = 0, int v1 = 0, int w1 = 0) : u(u1), v(v1), w(w1) {}
    bool operator<(const edge &e) const
    {
        return w < e.w;
    }
};

vector<edge> edges;
vector<int> parent(vNum + 1, -1);
vector<int> t[vNum + 1];

int find(int x)
{
    if (parent[x] < 0)
        return x;
    return parent[x] = find(parent[x]);
}

void merge(int u, int v)
{
    int root1 = find(u);
    int root2 = find(v);
    if (root1 != root2)
    {
        if (parent[root1] < parent[root2])
        {
            parent[root1] += parent[root2];
            parent[root2] = root1;
        }
        else
        {
            parent[root2] += parent[root1];
            parent[root1] = root2;
        }
    }
}

void kruskal(int n)
{
    sort(edges.begin(), edges.end());
    int count = 0;
    for (auto &e : edges)
    {
        if (find(e.u) != find(e.v))
        {
            merge(e.u, e.v);
            t[e.u].push_back(e.v);
            t[e.v].push_back(e.u);
            if (++count == n - 1)
                break;
        }
    }
}

int main()
{
    edges.push_back(edge(1, 2, 6));
    edges.push_back(edge(1, 3, 3));
    edges.push_back(edge(2, 4, 1));
    edges.push_back(edge(2, 6, 5));
    edges.push_back(edge(3, 4, 6));
    edges.push_back(edge(3, 5, 6));
    edges.push_back(edge(4, 5, 6));
    edges.push_back(edge(5, 6, 2));

    kruskal(6);

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
