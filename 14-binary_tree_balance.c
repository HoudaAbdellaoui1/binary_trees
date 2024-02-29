#include "binary_trees.h"

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(const binary_tree_t *tree) {
    if (tree == NULL)
        return 0;

    int left_height = height(tree->left);
    int right_height = height(tree->right);

    return 1 + max(left_height, right_height);
}

int binary_tree_balance(const binary_tree_t *tree) {
    if (tree == NULL)
        return 0;

    int left_height = height(tree->left);
    int right_height = height(tree->right);

    return left_height - right_height;
}
