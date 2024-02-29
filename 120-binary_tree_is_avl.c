#include "binary_trees.h"
#include <stdlib.h>

/**
 * is_avl - Checks if a binary tree is a valid AVL Tree recursively
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int is_avl(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return 1;

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    if (abs(left_height - right_height) > 1)
        return 0;

    if (!is_avl(tree->left) || !is_avl(tree->right))
        return 0;

    return 1;
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return 0;

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
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

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    if (!binary_tree_is_bst(tree))
        return 0;

    return is_avl(tree);
}
