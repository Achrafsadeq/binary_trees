#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 if not or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    
    size_t left_height = binary_tree_size(tree->left);
    size_t right_height = binary_tree_size(tree->right);

    return (left_height == right_height);
}

/**
 * heapify_up - ensures the max heap property is maintained by moving up
 * @node: pointer to the node to check and swap
 * Return: pointer to the final position of the node
 */
heap_t *heapify_up(heap_t *node)
{
    int temp;

    if (node == NULL || node->parent == NULL)
        return (node);

    while (node->parent && node->n > node->parent->n)
    {
        temp = node->n;
        node->n = node->parent->n;
        node->parent->n = temp;
        node = node->parent;
    }

    return (node);
}

/**
 * get_parent - finds the parent node for the new insertion
 * @root: pointer to the root of the tree
 * Return: pointer to the parent node where insertion should occur
 */
heap_t *get_parent(heap_t *root)
{
    heap_t *current;
    heap_t **queue;
    size_t size, i;
    
    size = binary_tree_size(root);
    queue = malloc(sizeof(heap_t *) * (size + 1));
    if (queue == NULL)
        return (NULL);

    i = 0;
    queue[i++] = root;
    for (size_t j = 0; j < i; j++)
    {
        current = queue[j];
        if (current->left)
            queue[i++] = current->left;
        if (current->right)
            queue[i++] = current->right;
    }

    for (size_t j = 0; j < i; j++)
    {
        current = queue[j];
        if (!current->left || !current->right)
        {
            free(queue);
            return (current);
        }
    }

    free(queue);
    return (NULL);
}

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;

    if (root == NULL)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (new_node == NULL)
        return (NULL);

    if (*root == NULL)
    {
        *root = new_node;
        return (new_node);
    }

    parent = get_parent(*root);
    if (parent == NULL)
    {
        free(new_node);
        return (NULL);
    }

    if (parent->left == NULL)
        parent->left = new_node;
    else
        parent->right = new_node;
    
    new_node->parent = parent;

    return (heapify_up(new_node));
}
