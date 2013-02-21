#ifndef _TREE_H_
#define _TREE_H_

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
};

struct Tree
{
    TreeNode *root;
};

Tree *createTree();
bool exists(Tree *tree, int value);
void addElement(Tree *tree, int value);
void preorder(Tree *tree);
void inorderLeft(Tree *tree);
void inorderRight(Tree *tree);
void postorder(Tree *tree);
int deleteMin(Tree *tree);
void deleteElement(Tree *tree, int value);
void removeTree(Tree *tree);

#endif
