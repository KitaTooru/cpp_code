#include <iostream>
using namespace std;
#define vNum 100

struct vertex
{
    int u;
    int w;
    vertex *next;
    vertex(int u1 = 0, int w1 = 0) : u(u1), w(w1), next(NULL) {}
};

typedef char datatype;
struct llNode
{
    datatype data[vNum];
    vertex *edges[vNum];
    int v, e;

    llNode() : v(0), e(0)
    {
        for (int i = 0; i < vNum; i++)
            edges[i] = NULL;
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
    int u, v, w;
    g = new llNode;
    cout << "输入顶点数和边数: ";
    cin >> g->v >> g->e;

    cout << "输入每条边（起点 终点 权值）:" << endl;
    for (int i = 0; i < g->e; i++)
    {
        cin >> u >> v >> w;
        add_edge(g, u, v, w);
    }
}

void print_adjList(llNode *g)
{
    cout << "邻接表表示:" << endl;
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

int main()
{
    llNode *g;
    create_linkList(g);
    print_adjList(g);
    return 0;
}
