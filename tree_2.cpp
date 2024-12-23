#include <iostream>
using namespace std;

typedef char datatype;
typedef struct TreeNode
{
    datatype data;
    TreeNode *left, *right;
    TreeNode() : left(NULL), right(NULL) {}
} *BTree;

BTree create_BTree(datatype data, BTree left, BTree right)
{
    BTree newNode = new TreeNode();
    newNode->data = data;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

int leafnum(BTree T)
{
    int count = 0;
    if (T == NULL)
        return 0;
    if (T->left == NULL && T->right == NULL)
        count = 1;
    return count + leafnum(T->left) + leafnum(T->right);
}

int main()
{
    BTree nodeD = create_BTree('D', NULL, NULL);
    BTree nodeE = create_BTree('E', NULL, NULL);
    BTree nodeF = create_BTree('F', NULL, NULL);
    BTree nodeB = create_BTree('B', nodeD, nodeE);
    BTree nodeC = create_BTree('C', NULL, nodeF);
    BTree root = create_BTree('A', nodeB, nodeC);

    int leafCount = leafnum(root);

    cout << "叶子节点的个数为: " << leafCount << endl;

    return 0;
}
