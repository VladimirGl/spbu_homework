#include <stdlib.h>
#include "bst.h"
#include <iostream>
using namespace std;

Tree *createTree() {
    Tree *tree = new Tree;
    tree->root = NULL;
    return tree;
}

void preorder(TreeNode *root) {
    if (root != NULL) {
        cout << root->value << endl;
        preorder(root->left);
        preorder(root->right);
    }
}

void preorder(Tree *tree) {
  preorder(tree->root);
}

void inorderLeft(TreeNode *root) {
    if (root != NULL) {
        inorderLeft(root->left);        
        cout << root->value << " ";        
        inorderLeft(root->right);
    }
}

void inorderLeft(Tree *tree) {
  inorderLeft(tree->root);
}

void inorderRight(TreeNode *root) {
    if (root != NULL) {
        inorderRight(root->right);        
        cout << root->value << " ";        
        inorderRight(root->left);
    }
}

void inorderRight(Tree *tree) {
  inorderRight(tree->root);
}


void postorder(TreeNode *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->value << endl;
    }
}

void postorder(Tree *tree) {
  postorder(tree->root);
}

bool exists(TreeNode *root, int value) {
    if (root == NULL)
        return false;
    if (root->value == value)
        return true;
    if (root->value > value)
        return exists(root->left, value);
    else
        return exists(root->right, value);
}

bool exists(Tree *tree, int value) {
    return exists(tree->root, value);
}

TreeNode *createNode(int value) {
    TreeNode *node = new TreeNode;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void addElement(TreeNode *&node, int value) {
    if (node == NULL) {
        node = createNode(value);
        return;
    }
    if (value < node->value)
        addElement(node->left, value);
    else
        addElement(node->right, value);
}

void addElement(Tree *tree, int value) {
    addElement(tree->root, value);
}


int deleteMin(TreeNode *&node) {
   if (node->left == NULL) {
        int result = node->value;
        TreeNode *temp = node;        
        node = node->right;
        temp = NULL;
        delete temp;
        return result;
   }
   else
       return deleteMin(node->left);
}

int deleteMin(Tree *tree) {
    deleteMin(tree->root);
}

void deleteElement(TreeNode *&node, int value) {
    if (node == NULL)
        return;
    if (value < node->value)
        deleteElement(node->left, value);
    else if (value > node->value)
  	    deleteElement(node->right, value);
    else if (node->left == NULL && node->right == NULL) {
  	    delete node;
  	    node = NULL;
    } else if (node->left == NULL) {
        TreeNode *temp = node;        
        node = node->right;
        delete temp;
    }
    else if (node->right == NULL) {
        TreeNode *temp = node;        
        node = node->left;
        delete temp;
   }
   else
       node->value = deleteMin(node->right);  
}

void deleteElement(Tree *tree, int value) {
    if (!exists(tree, value))
       return;
    deleteElement(tree->root, value);
}

void removeTree(TreeNode *&root) {
    if (root != NULL) {
        removeTree(root->left);
        removeTree(root->right);
        delete root;
        root = NULL;
    }
}

void removeTree(Tree *tree) {
  removeTree(tree->root);
}
