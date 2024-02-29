#include "binary_trees.h"

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    static const binary_tree_t *prev = NULL;

    if (tree == NULL)
        return 1;

    if (!binary_tree_is_bst(tree->left))
        return 0;

    if (prev != NULL && tree->n <= prev->n)
        return 0;

    prev = tree;

    return binary_tree_is_bst(tree->right);
}
