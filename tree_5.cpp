#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
typedef char datatype;

typedef struct TreeNode
{
    datatype data;
    TreeNode *left, *right;
    TreeNode() : left(NULL), right(NULL) {}
} *BTree;

BTree createNode(datatype data)
{
    BTree node = new TreeNode();
    node->data = data;
    return node;
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

BTree convert(const char *express)
{
    stack<BTree> nodes;
    stack<char> ops;

    for (int i = 0; express[i]; ++i)
    {
        if (isdigit(express[i]))
        {
            int num = 0;
            while (isdigit(express[i]))
            {
                num = num * 10 + (express[i] - '0');
                ++i;
            }
            --i;
            BTree node = createNode(num);
            nodes.push(node);
        }
        else if (express[i] == '(')
        {
            ops.push(express[i]);
        }
        else if (express[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                char op = ops.top();
                ops.pop();
                BTree right = nodes.top();
                nodes.pop();
                BTree left = nodes.top();
                nodes.pop();
                BTree node = createNode(op);
                node->left = left;
                node->right = right;
                nodes.push(node);
            }
            ops.pop();
        }
        else
        {
            while (!ops.empty() && precedence(ops.top()) >= precedence(express[i]))
            {
                char op = ops.top();
                ops.pop();
                BTree right = nodes.top();
                nodes.pop();
                BTree left = nodes.top();
                nodes.pop();
                BTree node = createNode(op);
                node->left = left;
                node->right = right;
                nodes.push(node);
            }
            ops.push(express[i]);
        }
    }

    while (!ops.empty())
    {
        char op = ops.top();
        ops.pop();
        BTree right = nodes.top();
        nodes.pop();
        BTree left = nodes.top();
        nodes.pop();
        BTree node = createNode(op);
        node->left = left;
        node->right = right;
        nodes.push(node);
    }

    return nodes.top();
}

double evaluate(BTree root)
{
    if (!root->left && !root->right)
        return root->data;

    double leftVal = evaluate(root->left);
    double rightVal = evaluate(root->right);

    switch (root->data)
    {
    case '+':
        return leftVal + rightVal;
    case '-':
        return leftVal - rightVal;
    case '*':
        return leftVal * rightVal;
    case '/':
        return leftVal / rightVal;
    }
    return 0;
}

int main()
{
    const char expression[] = "2+3*(5+8)/4-5";
    BTree bt = convert(expression);
    cout << "Result: " << evaluate(bt) << endl;
    return 0;
}
