#include <iostream>
using namespace std;

typedef int datatype;
typedef struct lrpNode
{
    datatype data;
    lrpNode *lc, *rc;
    lrpNode() : lc(NULL), rc(NULL) {}
} *lrpTree;

void midOrder(lrpTree t)
{
    if (t == NULL)
        return;
    midOrder(t->lc);
    cout << t->data << " ";
    midOrder(t->rc);
}

void is_bstTree(lrpTree t, bool &is_bst)
{
    static lrpTree pre = NULL;
    if (t == NULL)
        return;
    is_bstTree(t->lc, is_bst);
    if (pre != NULL && pre->data >= t->data)
    {
        is_bst = false;
        return;
    }
    pre = t;
    is_bstTree(t->rc, is_bst);
}

int main()
{
    lrpTree root = new lrpNode();
    root->data = 10;
    root->lc = new lrpNode();
    root->lc->data = 5;
    root->rc = new lrpNode();
    root->rc->data = 15;
    root->lc->lc = new lrpNode();
    root->lc->lc->data = 3;
    root->lc->rc = new lrpNode();
    root->lc->rc->data = 4;
    root->rc->lc = new lrpNode();
    root->rc->lc->data = 12;
    root->rc->rc = new lrpNode();
    root->rc->rc->data = 17;

    cout << "中序遍历结果: ";
    midOrder(root);
    cout << endl;

    bool is_bst = true;
    is_bstTree(root, is_bst);
    cout << "是否为二叉搜索树: " << (is_bst ? "是" : "否") << endl;

    return 0;
}