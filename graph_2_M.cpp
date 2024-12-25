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
    cout << "输入顶点数和边数: ";
    cin >> g.v >> g.e;

    for (i = 1; i <= g.v; i++)
    {
        for (j = 1; j <= g.v; j++)
        {
            g.edge[i][j] = INF;
        }
    }

    cout << "输入每条边（起点 终点 权值）:" << endl;
    for (i = 0; i < g.e; i++)
    {
        cin >> u >> v >> w;
        g.edge[u][v] = w;
    }
}

void printMatrix(adjMatrix g)
{
    cout << "图的邻接矩阵表示：" << endl;
    for (int i = 1; i <= g.v; i++)
    {
        for (int j = 1; j <= g.v; j++)
        {
            if (g.edge[i][j] == INF)
                cout << setw(5) << "INF";
            else
                cout << setw(5) << g.edge[i][j];
        }
        cout << endl;
    }
}

int main()
{
    adjMatrix g;
    create_adjMatrix(g);
    printMatrix(g);
    return 0;
}
