#include "binary_trees.h"
#include <stdlib.h>

/**
 * find_min - Finds the node with the minimum value in a BST
 * @node: Pointer to the root node of the tree
 *
 * Return: Pointer to the node with the minimum value
 */
bst_t *find_min(bst_t *node)
{
    bst_t *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST)
 * @root: Pointer to the root node of the tree
 * @value: Value to remove from the tree
 *
 * Return: Pointer to the new root node of the tree after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else
    {
        if (root->left == NULL)
        {
            bst_t *right_child = root->right;
            free(root);
            return right_child;
        }
        else if (root->right == NULL)
        {
            bst_t *left_child = root->left;
            free(root);
            return left_child;
        }

        bst_t *min_right = find_min(root->right);
        root->n = min_right->n;
        root->right = bst_remove(root->right, min_right->n);
    }

    return root;
}
