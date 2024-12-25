#include <iostream>
#include <iomanip>
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
        {
            edges[i] = NULL;
        }
    }
};

void add_edge(llNode *g, int u, int v, int w)
{
    vertex *tmp = new vertex(v, w);
    if (g->edges[u] == NULL)
    {
        g->edges[u] = tmp;
    }
    else
    {
        tmp->next = g->edges[u];
        g->edges[u] = tmp;
    }
}

void create_linkList(llNode *&g)
{
    int u, v, w;
    g = new llNode;
    cin >> g->v >> g->e;
    for (int i = 0; i < g->e; i++)
    {
        cin >> u >> v >> w;
        add_edge(g, u, v, w);
        add_edge(g, v, u, w);
    }
}

void print_adjList(llNode *g)
{
    cout << "边表表示: " << endl;
    for (int i = 1; i <= g->v; i++)
    {
        cout << "Vertex " << i << ": ";
        vertex *tmp = g->edges[i];
        while (tmp)
        {
            cout << "(" << tmp->u << ", " << tmp->w << ") ";
            tmp = tmp->next;
        }
        cout << endl;
    }
}

void adjVertex(llNode *g, int u)
{
    cout << "顶点 " << u << " 的邻接点: ";
    vertex *tmp = g->edges[u];
    while (tmp)
    {
        cout << tmp->u << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main()
{
    llNode *g;
    create_linkList(g);
    print_adjList(g);
    cout << endl;

    for (int i = 1; i <= g->v; i++)
    {
        adjVertex(g, i);
    }

    return 0;
}
