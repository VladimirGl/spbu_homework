#ifndef _TREE_H_
#define _TREE_H_

struct TreeNode
{
    double result;
    char value;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *create(char a);
bool isOperator(char a);
bool isBracketOrSpace(char a);
void add(TreeNode *&tree, char a[], int &i);
void removeTree(TreeNode *&root);
void postorder(TreeNode *root);
void preorder(TreeNode *root);

#endif
