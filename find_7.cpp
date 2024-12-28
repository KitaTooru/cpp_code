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
        t = new bstNode();
        t->key = k;
        return true;
    }
    if (k < t->key)
        return bst_insert(t->lc, k);
    else if (k > t->key)
        return bst_insert(t->rc, k);
    return false;
}

int kth_bst(bstTree t, int k)
{
    static int count = 0;
    static keytype result = -1;
    if (t == NULL)
        return -1;
    if (result == -1)
        kth_bst(t->lc, k);
    if (++count == k)
    {
        result = t->key;
        return result;
    }
    if (result == -1)
        kth_bst(t->rc, k);

    return result;
}

int main()
{
    bstTree root = new bstNode();
    root->key = 10;
    bst_insert(root, 5);
    bst_insert(root, 15);
    bst_insert(root, 3);
    bst_insert(root, 7);
    bst_insert(root, 12);
    bst_insert(root, 17);

    int k = 3;
    int kth = kth_bst(root, k);
    cout << "第" << k << "小键值: " << kth << endl;

    return 0;
}