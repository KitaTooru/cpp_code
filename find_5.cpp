#include <iostream>
using namespace std;

typedef struct avlNode
{
    int key, b;
    avlNode *lc, *rc;
    avlNode() : lc(NULL), rc(NULL), b(1) {}
} *avlTree;

int avl_height(avlTree avl)
{
    if (avl == NULL)
        return 0;

    int leftHeight = avl_height(avl->lc);
    int rightHeight = avl_height(avl->rc);

    avl->b = rightHeight - leftHeight;

    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    avlTree root = new avlNode();
    root->lc = new avlNode();
    root->rc = new avlNode();

    int height = avl_height(root);
    cout << "平衡二叉树高度: " << height << endl;

    return 0;
}
