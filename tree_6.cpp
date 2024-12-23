#include <iostream>
#include <queue>
#define M 20
using namespace std;

typedef char datatype;
typedef struct hutNode
{
    datatype data;
    int w, idx;
    int lc, rc;
    bool operator<(const hutNode &hn) const
    {
        return w > hn.w;
    }
} huTree[M << 1];

void huTree_create(huTree &t, const datatype data[], int w[], int m)
{
    int i;
    hutNode hn1, hn2, hn3;
    priority_queue<hutNode> f;
    for (int i = 1; i <= m; i++)
    {
        t[i].data = data[i - 1], t[i].w = w[i - 1], t[i].idx = i;
        t[i].lc = t[i].rc = -1;
        f.push(t[i]);
    }
    while (f.size() > 1)
    {
        hn1 = f.top(), f.pop();
        hn2 = f.top(), f.pop();
        hn3.data = 0, hn3.w = hn1.w + hn2.w;
        hn3.lc = hn1.idx, hn3.rc = hn2.idx;
        f.push(hn3);
        t[i++] = hn3;
    }
    t[0] = f.top(), t[0].idx = 0;
}

int main()
{
    datatype data[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    int weights[] = {15, 3, 14, 2, 6, 9, 16, 17};
    huTree tree;
    huTree_create(tree, data, weights, 8);
    for (int i = 0; i < 15; i++)
    {
        cout << tree[i].data << " " << tree[i].w << " " << tree[i].lc << " " << tree[i].rc << endl;
    }
    return 0;
}
