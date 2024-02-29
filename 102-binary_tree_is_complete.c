#include "binary_trees.h"

/**
 * count_nodes - Counts the total number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of nodes in the tree
 */
int count_nodes(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    return 1 + count_nodes(tree->left) + count_nodes(tree->right);
}

/**
 * count_nodes_at_level - Counts the number of nodes at a given level in a binary tree
 * @tree: Pointer to the root node of the tree
 * @level: The level to count nodes at
 *
 * Return: Number of nodes at the given level
 */
int count_nodes_at_level(const binary_tree_t *tree, int level)
{
    if (tree == NULL)
        return 0;

    if (level == 0)
        return 1;

    return count_nodes_at_level(tree->left, level - 1) + count_nodes_at_level(tree->right, level - 1);
}


/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    int level = 0, nodes = 1;
    const binary_tree_t *node = tree;

    while (node->left != NULL)
    {
        nodes *= 2;
        node = node->left;
        level++;
    }

    int count = count_nodes(tree);
    return (nodes - 1 + count_nodes_at_level(tree, level) == count);
}
