#include <iostream>
#include "bst.h"

using namespace std;


TreeNode *create(char a)
{
    TreeNode *head = new TreeNode;
    head->left = NULL;
    head->right = NULL;
    head->value = a;
    head->result = (a - 48);
    return head;
}

bool isOperator(char a) {
    if (a == '+') 
        return true;
    if (a == '-') 
        return true;
    if (a == '*') 
        return true;
    if (a == '/') 
        return true;
    return false;
}

bool isBracketOrSpace(char a) {
    if (a == ' ') 
        return true;
    if (a == '(') 
        return true;
    if (a == ')') 
        return true;
    return false;
}

void add(TreeNode *&tree, char a[], int &i)
{
    if (isBracketOrSpace(a[i]))
    {
        add(tree, a, ++i);
    }
    else
    {
        if(a[i] != '\0')
        {
            if(isOperator(a[i]))
            {
                tree = create(a[i++]);
                add(tree->left, a, i);
                add(tree->right, a, i);
            }
            else
            {
                tree = create(a[i++]);
            }
        }
        else
            return;
    }
}

void preorder(TreeNode *root) {
    if (root != NULL) {
        cout << root->value << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TreeNode *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->value << " ";
    }
}

void removeTree(TreeNode *&root) {
    if (root != NULL) {
        removeTree(root->left);
        removeTree(root->right);
        delete root;
        root = NULL;
    }
}
