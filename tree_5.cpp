#include <iostream>
#include <map>
using namespace std;
#define N 100

map<char, int> m;
typedef char datatype;
typedef struct TreeNode
{
    datatype data;
    TreeNode *left, *right;
    TreeNode() : left(NULL), right(NULL) {}
} *BTree;
typedef struct rpn_node
{
    bool tag;
    union
    {
        int v;
        char op;
    } data;
} rpn[N];
