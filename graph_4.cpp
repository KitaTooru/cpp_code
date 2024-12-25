#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define vNum 100

bool vis[vNum];
vector<int> connectedComponents[vNum];
int componentIndex = 0;

void dfs(vector<int> g[vNum], int cur)
{
    vis[cur] = true;
    connectedComponents[componentIndex].push_back(cur);

    for (int u : g[cur])
    {
        if (!vis[u])
        {
            dfs(g, u);
        }
    }
}

void findConnectedComponents(vector<int> g[vNum], int v)
{
    memset(vis, 0, sizeof(vis));
    componentIndex = 0;

    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            connectedComponents[componentIndex].clear();
            dfs(g, i);
            componentIndex++;
        }
    }
}

int main()
{
    int v, e;
    cout << "请输入图的顶点数和边数: ";
    cin >> v >> e;

    vector<int> g[vNum];

    cout << "请输入每条边的两个顶点: ";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    findConnectedComponents(g, v);

    cout << "连通分量个数: " << componentIndex << endl;
    for (int i = 0; i < componentIndex; i++)
    {
        cout << "连通子图 " << i + 1 << ": ";
        for (int node : connectedComponents[i])
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
