#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define vNum 100

struct vertex
{
    int u;
    vertex *next;
    vertex(int u1 = 0) : u(u1), next(NULL) {}
};

typedef char datatype;
struct llNode
{
    vertex *edges[vNum];
    int v, e;
    llNode() : v(0), e(0)
    {
        for (int i = 0; i < vNum; i++)
        {
            edges[i] = NULL;
        }
    }
};

void add_edge(llNode *g, int u, int v)
{
    vertex *tmp = new vertex(v);
    if (g->edges[u] == NULL)
    {
        g->edges[u] = tmp;
    }
    else
    {
        vertex *prev = NULL, *curr = g->edges[u];
        while (curr && curr->u > v)
        {
            prev = curr;
            curr = curr->next;
        }
        if (prev == NULL)
        {
            tmp->next = g->edges[u];
            g->edges[u] = tmp;
        }
        else
        {
            prev->next = tmp;
            tmp->next = curr;
        }
    }
}

void create_graph(llNode *&g, int vertices, int edges, vector<pair<int, int>> edgeList)
{
    g = new llNode;
    g->v = vertices;
    g->e = edges;
    for (auto edge : edgeList)
    {
        add_edge(g, edge.first, edge.second);
    }
}

bool topological_sort(llNode *g, vector<int> &result)
{
    int ind[vNum] = {0};
    for (int i = 0; i < g->v; i++)
    {
        vertex *tmp = g->edges[i];
        while (tmp)
        {
            ind[tmp->u]++;
            tmp = tmp->next;
        }
    }

    queue<int> q;
    for (int i = 0; i < g->v; i++)
    {
        if (ind[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        result.push_back(u);

        vertex *tmp = g->edges[u];
        while (tmp)
        {
            ind[tmp->u]--;
            if (ind[tmp->u] == 0)
            {
                q.push(tmp->u);
            }
            tmp = tmp->next;
        }
    }

    return result.size() == g->v;
}

int main()
{
    llNode *graph;
    int vertices = 9;
    int edges = 13;
    vector<pair<int, int>> edgeList = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 4}, {2, 5}, {3, 6}, {3, 7}, {4, 7}, {4, 8}, {5, 7}, {6, 7}, {7, 8}};

    create_graph(graph, vertices, edges, edgeList);

    vector<int> result;
    if (topological_sort(graph, result))
    {
        cout << "拓扑排序序列: ";
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "图中存在环，无法进行拓扑排序" << endl;
    }

    return 0;
}
