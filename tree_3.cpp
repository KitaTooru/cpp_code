#include <iostream>
using namespace std;

typedef char datatype;
typedef struct thNode
{
    datatype data;
    thNode *lc, *rc;
    bool ltag, rtag;
    thNode() : lc(NULL), rc(NULL), ltag(false), rtag(false) {}
} *thTree;

thTree pre = NULL;

void InThread(thTree T)
{
    if (T)
    {
        if (!T->ltag)
            InThread(T->lc);
        if (!T->lc)
        {
            T->ltag = true;
            T->lc = pre;
        }
        if (pre && !pre->rc)
        {
            pre->rtag = true;
            pre->rc = T;
        }
        pre = T;
        if (!T->rtag)
            InThread(T->rc);
    }
}

void CreateInThread(thTree T)
{
    pre = NULL;
    if (T)
    {
        InThread(T);
        if (pre)
        {
            pre->rtag = true;
            pre->rc = NULL;
        }
    }
}

void LInsert(thTree P, thTree Q)
{
    if (!P || !Q)
        return;
    Q->lc = P->lc;
    Q->ltag = P->ltag;
    Q->rc = P;
    Q->rtag = true;
    P->lc = Q;
    P->ltag = false;
    if (!Q->ltag && Q->lc)
    {
        thTree temp = Q->lc;
        while (!temp->rtag)
            temp = temp->rc;
        temp->rc = Q;
    }
}

void RInsert(thTree P, thTree Q)
{
    if (!P || !Q)
        return;
    Q->rc = P->rc;
    Q->rtag = P->rtag;
    Q->lc = P;
    Q->ltag = true;
    P->rc = Q;
    P->rtag = false;
    if (!Q->rtag && Q->rc)
    {
        thTree temp = Q->rc;
        while (!temp->ltag)
            temp = temp->lc;
        temp->lc = Q;
    }
}

void InOrder(thTree T)
{
    thTree p = T;
    while (p)
    {
        while (!p->ltag)
            p = p->lc;
        cout << p->data << " ";
        while (p->rtag && p->rc)
        {
            p = p->rc;
            cout << p->data << " ";
        }
        p = p->rc;
    }
}

int main()
{
    thTree root = new thNode();
    root->data = 'A';

    thTree nodeB = new thNode();
    nodeB->data = 'B';
    LInsert(root, nodeB);

    thTree nodeC = new thNode();
    nodeC->data = 'C';
    RInsert(root, nodeC);

    thTree nodeD = new thNode();
    nodeD->data = 'D';
    LInsert(nodeB, nodeD);

    thTree nodeE = new thNode();
    nodeE->data = 'E';
    RInsert(nodeB, nodeE);

    CreateInThread(root);

    cout << "中序输出二叉树结点为: ";
    InOrder(root);
    cout << endl;

    return 0;
}
