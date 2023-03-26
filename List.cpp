#include "List.h"

pTree newTree(int x)
{
    pTree temp = new Tree;
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

pTree Push(pTree root, int x)
{
    if (root == NULL)
    {
        root = new Tree;
        root->data = x;
        root->left = root->right = NULL;
    }

    if (root->data % 2 == 0 && root->data != 1)
    {
        if (root->left != NULL) Push(root->left, root->data);
        else
        {
            root->left = new Tree;
            root->left->left = root->left->right = NULL;
            root->left->data = root->data / 2;
            Push(root->left, root->data / 2);
        }
    }

    if (root->data % 2 != 0 && root->data != 1)
    {
        if (root->right != NULL) Push(root->right, root->data - root->data / 2);
        else
        {
            root->right = new Tree;
            root->right->left = root->right->right = NULL;
            root->right->data = root->data - root->data / 2;
            Push(root->right, root->data - root->data / 2);
        }

        if (root->left != NULL) Push(root->left, root->data);
        else
        {
            root->left = new Tree;
            root->left->left = root->left->right = NULL;
            root->left->data = root->data / 2;
            Push(root->left, root->data / 2);
        }
    }

    return root;
}

void print_Tree(pTree root, int level, std::ostream& stream)
{
    if (root)
    {
        print_Tree(root->right, level + 1, stream);
        for (int i = 0; i < level; i++)
            stream << "   ";
        stream << root->data << "\n";
        print_Tree(root->left, level + 1, stream);
    }
}