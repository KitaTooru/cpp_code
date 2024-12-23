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

int count2(BTree T)
{
    int count = 0;
    if (T == NULL)
        return 0;
    if (T->left != NULL && T->right != NULL)
        count = 1;
    return count + count2(T->left) + count2(T->right);
}

int main()
{
    BTree nodeD = create_BTree('D', NULL, NULL);
    BTree nodeE = create_BTree('E', NULL, NULL);
    BTree nodeF = create_BTree('F', NULL, NULL);
    BTree nodeB = create_BTree('B', nodeD, nodeE);
    BTree nodeC = create_BTree('C', NULL, nodeF);
    BTree root = create_BTree('A', nodeB, nodeC);

    int degree2Count = count2(root);

    cout << "度为2的节点个数为: " << degree2Count << endl;

    return 0;
}
