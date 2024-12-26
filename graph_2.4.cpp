#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define vNum 6
#define INF INT_MAX

void Floyd(int graph[vNum][vNum], int dist[vNum][vNum], int next[vNum][vNum])
{
    for (int i = 0; i < vNum; i++)
    {
        for (int j = 0; j < vNum; j++)
        {
            dist[i][j] = graph[i][j];
            if (graph[i][j] != INF && i != j)
            {
                next[i][j] = j;
            }
            else
            {
                next[i][j] = -1;
            }
        }
    }

    for (int k = 0; k < vNum; k++)
    {
        for (int i = 0; i < vNum; i++)
        {
            for (int j = 0; j < vNum; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

int findCenter(int dist[vNum][vNum])
{
    int eccentricities[vNum] = {0};
    for (int i = 0; i < vNum; i++)
    {
        for (int j = 0; j < vNum; j++)
        {
            if (dist[i][j] != INF)
            {
                eccentricities[i] = max(eccentricities[i], dist[i][j]);
            }
        }
    }
    int center = 0;
    for (int i = 1; i < vNum; i++)
    {
        if (eccentricities[i] < eccentricities[center])
        {
            center = i;
        }
    }
    return center;
}

void Warshall(int graph[vNum][vNum], int closure[vNum][vNum])
{
    for (int i = 0; i < vNum; i++)
    {
        for (int j = 0; j < vNum; j++)
        {
            closure[i][j] = graph[i][j] != INF ? 1 : 0;
        }
    }

    for (int k = 0; k < vNum; k++)
    {
        for (int i = 0; i < vNum; i++)
        {
            for (int j = 0; j < vNum; j++)
            {
                closure[i][j] = closure[i][j] || (closure[i][k] && closure[k][j]);
            }
        }
    }
}

int main()
{
    int graph[vNum][vNum] = {
        {0, 1, INF, INF, INF, 5},
        {INF, 0, 3, INF, INF, INF},
        {INF, INF, 0, 2, INF, INF},
        {INF, INF, 3, 0, INF, INF},
        {2, INF, INF, 4, 0, INF},
        {INF, INF, INF, 1, 2, 0}};

    int dist[vNum][vNum], next[vNum][vNum];
    Floyd(graph, dist, next);

    cout << "Floyd算法求得的最短路径矩阵：" << endl;
    for (int i = 0; i < vNum; i++)
    {
        for (int j = 0; j < vNum; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    int center = findCenter(dist);
    cout << "图的中心点为: " << center + 1 << endl;

    int closure[vNum][vNum];
    Warshall(graph, closure);
    cout << "Warshall算法求得的传递闭包矩阵：" << endl;
    for (int i = 0; i < vNum; i++)
    {
        for (int j = 0; j < vNum; j++)
        {
            cout << closure[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
