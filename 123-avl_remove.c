#include <stdlib.h>
#include "binary_trees.h"

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree for removing a node
 * @value: Value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removing the value
 */
avl_t *avl_remove(avl_t *root, int value)
{
    if (root == NULL)
        return NULL;

    /* Perform standard BST deletion */
    if (value < root->n)
    {
        root->left = avl_remove(root->left, value);
    }
    else if (value > root->n)
    {
        root->right = avl_remove(root->right, value);
    }
    else
    {
        /* Node to be deleted found */
        if (root->left == NULL || root->right == NULL)
        {
            avl_t *temp = root->left ? root->left : root->right;

            /* No child or one child case */
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp; /* Copy the contents of the non-empty child */
            }

            free(temp);
        }
        else
        {
            /* Node with two children: Get the inorder successor (smallest in the right subtree) */
            avl_t *temp = binary_tree_minimum(root->right);

            /* Copy the inorder successor's data to this node */
            root->n = temp->n;

            /* Delete the inorder successor */
            root->right = avl_remove(root->right, temp->n);
        }
    }

    /* If the tree had only one node then return */
    if (root == NULL)
        return root;

    /* Update height of the current node */
    root->height = 1 + MAX(binary_tree_height(root->left), binary_tree_height(root->right));

    /* Get the balance factor of this node to check whether this node became unbalanced */
    int balance = binary_tree_balance(root);

    /* Left Left Case */
    if (balance > 1 && binary_tree_balance(root->left) >= 0)
        return binary_tree_rotate_right(root);

    /* Left Right Case */
    if (balance > 1 && binary_tree_balance(root->left) < 0)
    {
        root->left = binary_tree_rotate_left(root->left);
        return binary_tree_rotate_right(root);
    }

    /* Right Right Case */
    if (balance < -1 && binary_tree_balance(root->right) <= 0)
        return binary_tree_rotate_left(root);

    /* Right Left Case */
    if (balance < -1 && binary_tree_balance(root->right) > 0)
    {
        root->right = binary_tree_rotate_right(root->right);
        return binary_tree_rotate_left(root);
    }

    return root;
}
