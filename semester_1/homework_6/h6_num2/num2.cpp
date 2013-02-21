#include <iostream>
#include <fstream>
#include "bst.h"

using namespace std;

void calcNode(TreeNode *&head)
{
    double res = 0;
    switch (head->value)
    {
    case '+':
        res = (head->left->result) + (head->right->result);
        break;
    case '-':
        res = (head->left->result) - (head->right->result);
        break;
    case '/':
        res = (head->left->result) / (head->right->result);
        break;
    case '*':
        res = (head->left->result) * (head->right->result);
        break;
    }
    delete head->left;
    head->left = NULL;
    delete head->right;
    head->right = NULL;
    head->value = '0';
    head->result = res;
}

void calcTree(TreeNode *&head)
{
    if (isOperator(head->value))
    {
        if (!isOperator(head->left->value) && !isOperator(head->right->value))
            calcNode(head);
        else
        {
            if (isOperator(head->left->value))
                calcTree(head->left);
            if (isOperator(head->right->value))
                calcTree(head->right);
            calcTree(head);
        }
    }
}

int main()
{ 
    ifstream text("input.txt");
    if (!text)
    {
        cerr << "Error reading a file" << endl;
        getchar();
        return 1;
    } 
    cout << "This program for the parse tree of an\narithmetic expression computes its value" << endl << endl;
    char str[255];
    text.getline(str, 255);
    cout << "Input expression\n" << str << endl;
    TreeNode *head = new TreeNode;
    int i = 0;
    add(head, str, i);
    cout << "\nPrefix notation\n";
    preorder(head);
    cout << endl << endl;
    cout << "Postfix notation\n";
    postorder(head);
    cout << endl;
    calcTree(head);
    cout << "\nThe expression is " << (head->result);
    cout << endl << endl;
    cout << "To exit the program enter the character ";
    cin >> i;
    text.close();
    removeTree(head);
    delete head;
    return 0;
}
