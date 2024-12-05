#include "binary_trees.h"

/**
 * find_min - Finds the node with the minimum value in a subtree
 * @node: Pointer to the root of the subtree
 * Return: Pointer to the node with the minimum value
 */
avl_t *find_min(avl_t *node)
{
    while (node->left)
        node = node->left;
    return (node);
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root of the tree
 * @value: The value to remove
 * Return: Pointer to the new root after removal
 */
avl_t *avl_remove(avl_t *root, int value)
{
    avl_t *successor;

    if (!root)
        return (NULL);

    if (value < root->n)
        root->left = avl_remove(root->left, value);
    else if (value > root->n)
        root->right = avl_remove(root->right, value);
    else
    {
        if (!root->left && !root->right) /* Leaf node */
        {
            free(root);
            return (NULL);
        }
        else if (!root->left || !root->right) /* One child */
        {
            successor = root->left ? root->left : root->right;
            successor->parent = root->parent;
            free(root);
            return (successor);
        }
        else /* Two children */
        {
            successor = find_min(root->right);
            root->n = successor->n;
            root->right = avl_remove(root->right, successor->n);
        }
    }

    /* Update balance factor and rebalance if necessary */
    int balance = binary_tree_balance(root);

    if (balance > 1 && binary_tree_balance(root->left) >= 0) /* Left-Left */
        return (binary_tree_rotate_right(root));
    if (balance > 1 && binary_tree_balance(root->left) < 0) /* Left-Right */
    {
        root->left = binary_tree_rotate_left(root->left);
        return (binary_tree_rotate_right(root));
    }
    if (balance < -1 && binary_tree_balance(root->right) <= 0) /* Right-Right */
        return (binary_tree_rotate_left(root));
    if (balance < -1 && binary_tree_balance(root->right) > 0) /* Right-Left */
    {
        root->right = binary_tree_rotate_right(root->right);
        return (binary_tree_rotate_left(root));
    }

    return (root);
}
