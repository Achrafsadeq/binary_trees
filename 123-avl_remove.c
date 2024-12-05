#include "binary_trees.h"

/**
 * find_successor - Finds the in-order successor of a node
 * @node: Node to find successor for
 * Return: Pointer to the in-order successor
 */
avl_t *find_successor(avl_t *node)
{
    avl_t *current = node->right;
    while (current->left != NULL)
        current = current->left;
    return current;
}

/**
 * avl_remove_node - Removes a node from the AVL tree
 * @root: Root of the tree
 * @node: Node to remove
 * Return: New root after removal and rebalancing
 */
avl_t *avl_remove_node(avl_t *root, avl_t *node)
{
    avl_t *replacement = NULL;

    // Case 1: Leaf node or single child
    if (node->left == NULL || node->right == NULL)
    {
        avl_t *child = node->left ? node->left : node->right;

        if (child == NULL)  // Leaf node
        {
            if (node->parent && node->parent->left == node)
                node->parent->left = NULL;
            else if (node->parent)
                node->parent->right = NULL;
            replacement = node->parent;
        }
        else  // Single child
        {
            child->parent = node->parent;
            if (node->parent && node->parent->left == node)
                node->parent->left = child;
            else if (node->parent)
                node->parent->right = child;
            replacement = child;
        }

        if (node == root)
            root = replacement;

        free(node);
    }
    else  // Two children case
    {
        avl_t *successor = find_successor(node);
        node->n = successor->n;
        root = avl_remove_node(root, successor);
        return root;
    }

    // Rebalance the tree
    while (replacement)
    {
        int balance = binary_tree_balance(replacement);

        if (balance > 1)
        {
            if (binary_tree_balance(replacement->left) < 0)
                replacement->left = binary_tree_rotate_left(replacement->left);
            replacement = binary_tree_rotate_right(replacement);
        }
        else if (balance < -1)
        {
            if (binary_tree_balance(replacement->right) > 0)
                replacement->right = binary_tree_rotate_right(replacement->right);
            replacement = binary_tree_rotate_left(replacement);
        }

        if (replacement->parent == NULL)
            root = replacement;

        replacement = replacement->parent;
    }

    return root;
}

/**
 * avl_remove - Removes a node with a specific value from the AVL tree
 * @root: Root of the tree
 * @value: Value to remove
 * Return: New root after removal and rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
    avl_t *node_to_remove = NULL;
    avl_t *current = root;

    // Find the node to remove
    while (current)
    {
        if (current->n == value)
        {
            node_to_remove = current;
            break;
        }
        else if (value < current->n)
            current = current->left;
        else
            current = current->right;
    }

    // If node not found, return original root
    if (node_to_remove == NULL)
        return root;

    return avl_remove_node(root, node_to_remove);
}
