#include <iostream>
#include <iomanip>
#define eNum 100
#define INF 999999
using namespace std;

typedef char datatype;
struct adjMatrix
{
    datatype data[eNum];
    int edge[eNum][eNum];
    int v;
    int e;
};

void create_adjMatrix(adjMatrix &g)
{
    int i, j, u, v, w;
    cin >> g.v >> g.e;
    for (i = 1; i <= g.v; i++)
    {
        for (j = 1; j <= g.v; j++)
        {
            g.edge[i][j] = INF;
        }
    }
    for (i = 0; i < g.e; i++)
    {
        cin >> u >> v >> w;
        g.edge[u][v] = w;
        g.edge[v][u] = w;
    }
}

void adjVertex(adjMatrix g, int u)
{
    for (int i = 1; i <= g.v; i++)
    {
        if (g.edge[u][i] != INF)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void printMatrix(adjMatrix g)
{
    cout << "图的邻接矩阵表示：" << endl;
    for (int i = 1; i <= g.v; i++)
    {
        for (int j = 1; j <= g.v; j++)
        {
            if (i == j)
            {
                cout << setw(4) << "INF";
            }
            else if (g.edge[i][j] == INF)
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

int main()
{
    adjMatrix g;
    create_adjMatrix(g);
    printMatrix(g);
    cout << endl;

    for (int i = 1; i <= g.v; i++)
    {
        cout << "顶点 " << i << " 的邻接点: ";
        adjVertex(g, i);
    }

    return 0;
}
