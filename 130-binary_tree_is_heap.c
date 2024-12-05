#include "binary_trees.h"
#include <stdbool.h>

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 * @index: Index of the current node
 * @size: Total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t size)
{
    if (!tree)
        return (1);
    if (index >= size)
        return (0);
    return (is_complete(tree->left, 2 * index + 1, size) &&
            is_complete(tree->right, 2 * index + 2, size));
}

/**
 * max_heap_property - Checks if a binary tree satisfies the max heap property
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree satisfies the max heap property, 0 otherwise
 */
int max_heap_property(const binary_tree_t *tree)
{
    if (!tree)
        return (1);
    if (tree->left && tree->left->n > tree->n)
        return (0);
    if (tree->right && tree->right->n > tree->n)
        return (0);
    return (max_heap_property(tree->left) && max_heap_property(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    size_t size;

    if (!tree)
        return (0);

    size = binary_tree_size(tree);
    if (!is_complete(tree, 0, size))
        return (0);

    if (!max_heap_property(tree))
        return (0);

    return (1);
}
