#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>

using namespace std;

#define INF 99999
#define vNum 100

// 邻接矩阵表示
struct adjMatrix
{
    int edge[vNum][vNum];
    int v;
    int e;
};

void create_adjMatrix(adjMatrix &g)
{
    cout << "请输入顶点数和边数：";
    cin >> g.v >> g.e;
    for (int i = 1; i <= g.v; i++)
    {
        for (int j = 1; j <= g.v; j++)
        {
            g.edge[i][j] = (i == j) ? 0 : INF;
        }
    }
    cout << "请输入每条边（起点 终点 权重）：\n";
    for (int i = 0; i < g.e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.edge[u][v] = w;
        g.edge[v][u] = w;
    }
}

void printMatrix(const adjMatrix &g)
{
    cout << "图的邻接矩阵表示：\n";
    for (int i = 1; i <= g.v; i++)
    {
        for (int j = 1; j <= g.v; j++)
        {
            if (g.edge[i][j] == INF)
            {
                cout << setw(4) << "INF";
            }
            else
            {
                cout << setw(4) << g.edge[i][j];
            }
        }
        cout << endl;
    }
}

// 邻接表表示
struct vertex
{
    int u;
    int w;
    vertex *next;
    vertex(int u1 = 0, int w1 = 0) : u(u1), w(w1), next(NULL) {}
};

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

void add_edge(llNode *g, int u, int v, int w)
{
    vertex *tmp = new vertex(v, w);
    tmp->next = g->edges[u];
    g->edges[u] = tmp;
}

void create_linkList(llNode *&g)
{
    g = new llNode;
    cout << "请输入顶点数和边数：";
    cin >> g->v >> g->e;
    cout << "请输入每条边（起点 终点 权重）：\n";
    for (int i = 0; i < g->e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(g, u, v, w);
        add_edge(g, v, u, w);
    }
}

void print_adjList(llNode *g)
{
    cout << "图的邻接表表示：\n";
    for (int i = 1; i <= g->v; i++)
    {
        cout << "顶点 " << i << ": ";
        vertex *tmp = g->edges[i];
        while (tmp)
        {
            cout << "(" << tmp->u << ", " << tmp->w << ") ";
            tmp = tmp->next;
        }
        cout << endl;
    }
}

// dfs
bool vis[vNum];
vector<int> dfs_order;

void dfs(vector<int> g[vNum], int cur)
{
    vis[cur] = true;
    dfs_order.push_back(cur);
    for (int i = 0; i < g[cur].size(); i++)
    {
        int next = g[cur][i];
        if (!vis[next])
        {
            dfs(g, next);
        }
    }
}

// bfs
vector<int> bfs_order;

void bfs(vector<int> g[vNum], int start)
{
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    vis[start] = true;
    q.push(start);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        bfs_order.push_back(cur);
        for (int i = 0; i < g[cur].size(); i++)
        {
            int next = g[cur][i];
            if (!vis[next])
            {
                vis[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    adjMatrix gMatrix;
    llNode *gList;
    vector<int> adj[vNum];

    create_adjMatrix(gMatrix);
    printMatrix(gMatrix);

    create_linkList(gList);
    print_adjList(gList);

    for (int i = 1; i <= gMatrix.v; i++)
    {
        for (int j = 1; j <= gMatrix.v; j++)
        {
            if (gMatrix.edge[i][j] != INF && gMatrix.edge[i][j] != 0)
            {
                adj[i].push_back(j);
            }
        }
    }

    // dfs
    memset(vis, 0, sizeof(vis));
    dfs_order.clear();
    dfs(adj, 1);
    cout << "深度优先搜索顺序：";
    for (int v : dfs_order)
    {
        cout << v << " ";
    }
    cout << endl;

    // bfs
    bfs_order.clear();
    bfs(adj, 1);
    cout << "广度优先搜索顺序：";
    for (int v : bfs_order)
    {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
