#include "binary_trees.h"
#include <stdlib.h>

/**
 * enqueue - Adds a node to the queue
 * @queue: Pointer to the queue
 * @node: Pointer to the node to enqueue
 */
void enqueue(queue_t **queue, const binary_tree_t *node)
{
    queue_t *new_node = malloc(sizeof(queue_t));
    if (new_node == NULL)
        exit(1);

    new_node->node = node;
    new_node->next = NULL;

    if (*queue == NULL)
        *queue = new_node;
    else
    {
        queue_t *current = *queue;
        while (current->next != NULL)
            current = current->next;
        current->next = new_node;
    }
}

/**
 * dequeue - Removes and returns the front node of the queue
 * @queue: Pointer to the queue
 * Return: Pointer to the front node of the queue
 */
const binary_tree_t *dequeue(queue_t **queue)
{
    if (*queue == NULL)
        return NULL;

    const binary_tree_t *front = (*queue)->node;
    queue_t *temp = *queue;
    *queue = (*queue)->next;
    free(temp);
    return front;
}
/**
 * binary_tree_levelorder - Performs a level-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    queue_t *queue = NULL;
    const binary_tree_t *current;

    enqueue(&queue, tree);

    while (queue != NULL)
    {
        current = dequeue(&queue);
        func(current->n);

        if (current->left != NULL)
            enqueue(&queue, current->left);
        if (current->right != NULL)
            enqueue(&queue, current->right);
    }
}