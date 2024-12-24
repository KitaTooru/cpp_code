#include <iostream>
#include <queue>
#include <vector>
#include <string>
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
    int i = 1;
    hutNode hn1, hn2, hn3;
    priority_queue<hutNode> f;
    for (int j = 1; j <= m; j++)
    {
        t[j].data = data[j - 1], t[j].w = w[j - 1], t[j].idx = j;
        t[j].lc = t[j].rc = -1;
        f.push(t[j]);
    }
    while (f.size() > 1)
    {
        hn1 = f.top(), f.pop();
        hn2 = f.top(), f.pop();
        hn3.data = 0, hn3.w = hn1.w + hn2.w;
        hn3.lc = hn1.idx, hn3.rc = hn2.idx;
        hn3.idx = m + i++;
        f.push(hn3);
        t[m + i - 1] = hn3;
    }
    t[0] = f.top(), t[0].idx = 0;
}

void calculate_wpl(huTree &t, int root, int depth, int &wpl, string &expression)
{
    if (root == -1)
        return;
    if (t[root].lc == -1 && t[root].rc == -1)
    {
        wpl += t[root].w * depth;
        if (!expression.empty())
            expression += " + ";
        expression += to_string(t[root].w) + " * " + to_string(depth);
    }
    calculate_wpl(t, t[root].lc, depth + 1, wpl, expression);
    calculate_wpl(t, t[root].rc, depth + 1, wpl, expression);
}

int main()
{
    datatype data[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    int weights[] = {15, 3, 14, 2, 6, 9, 16, 17};
    huTree tree;
    huTree_create(tree, data, weights, 8);

    int wpl = 0;
    string expression = "";
    calculate_wpl(tree, tree[0].idx, 0, wpl, expression);

    cout << "带权路径长：" << expression << " = " << wpl << endl;

    return 0;
}
