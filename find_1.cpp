#include <iostream>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode *insert(TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return new TreeNode(value);
    }
    if (value < root->value)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}

void inOrderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->value << " ";
    inOrderTraversal(root->right);
}

int main()
{
    int data[] = {30, 15, 28, 20, 24, 10, 12, 68, 35, 50, 46, 55};
    int n = sizeof(data) / sizeof(data[0]);

    TreeNode *root = nullptr;
    for (int i = 0; i < n; ++i)
    {
        root = insert(root, data[i]);
    }

    cout << "排序后: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}