#include <iostream>
using namespace std;

typedef int keytype;
typedef struct bstNode
{
    keytype key;
    bstNode *lc, *rc;
    bstNode() : lc(NULL), rc(NULL) {}
} *bstTree;

bool bst_insert(bstTree &t, keytype k)
{
    if (t == NULL)
    {
        t = new bstNode, t->key = k;
        return true;
    }
    if (t->key > k)
        return bst_insert(t->lc, k);
    else
        return bst_insert(t->rc, k);
    return false;
}

void midOrder(bstTree rt)
{
    if (rt == NULL)
        return;
    midOrder(rt->lc);
    cout << rt->key << " ";
    midOrder(rt->rc);
}

int main()
{
    bstTree t = NULL;
    keytype a[] = {30, 15, 28, 20, 24, 10, 12, 68, 35, 50, 46, 55};
    for (int i = 0; i < 10; i++)
    {
        bst_insert(t, a[i]);
    }
    cout << "中序遍历结果：";
    midOrder(t);
    return 0;
}