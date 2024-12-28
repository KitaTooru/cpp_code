#include <iostream>
using namespace std;

typedef int keytype;
typedef struct avlNode
{
    keytype key;
    int h;
    avlNode *lc, *rc;
    avlNode() : key(0), h(1), lc(NULL), rc(NULL) {}
} *avlTree;

int avl_height(avlTree avl)
{
    return avl == NULL ? 0 : avl->h;
}

avlTree LL(avlTree A)
{
    avlTree B = A->lc;
    A->lc = B->rc;
    B->rc = A;
    A->h = max(avl_height(A->lc), avl_height(A->rc)) + 1;
    B->h = max(avl_height(B->lc), avl_height(B->rc)) + 1;
    return B;
}

avlTree RR(avlTree A)
{
    avlTree B = A->rc;
    A->rc = B->lc;
    B->lc = A;
    A->h = max(avl_height(A->lc), avl_height(A->rc)) + 1;
    B->h = max(avl_height(B->lc), avl_height(B->rc)) + 1;
    return B;
}

avlTree LR(avlTree A)
{
    A->lc = RR(A->lc);
    return LL(A);
}

avlTree RL(avlTree A)
{
    A->rc = LL(A->rc);
    return RR(A);
}

bool avl_insert(avlTree &t, keytype k)
{
    if (t == NULL)
    {
        t = new avlNode;
        t->key = k;
        return true;
    }
    if (k < t->key)
    {
        if (!avl_insert(t->lc, k))
            return false;
        if (avl_height(t->lc) - avl_height(t->rc) > 1)
        {
            if (k < t->lc->key)
                t = LL(t);
            else
                t = LR(t);
        }
    }
    else if (k > t->key)
    {
        if (!avl_insert(t->rc, k))
            return false;
        if (avl_height(t->rc) - avl_height(t->lc) > 1)
        {
            if (k > t->rc->key)
                t = RR(t);
            else
                t = RL(t);
        }
    }
    else
    {
        return false;
    }
    t->h = max(avl_height(t->lc), avl_height(t->rc)) + 1;
    return true;
}

void midOrder(avlTree t)
{
    if (t == NULL)
        return;
    midOrder(t->lc);
    cout << t->key << " ";
    midOrder(t->rc);
}

int main()
{
    avlTree t = NULL;
    keytype a[] = {51, 28, 9, 33, 42, 70, 62, 1, 3};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++)
    {
        avl_insert(t, a[i]);
    }
    cout << "中序遍历AVL树: " << endl;
    midOrder(t);
    cout << endl;
    return 0;
}
