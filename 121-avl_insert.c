#include "binary_trees.h"

/**
 * balance_avl - Balances an AVL tree after insertion
 * @tree: Pointer to the root node of the AVL subtree
 * @value: Value to help decide rotation direction
 * Return: Pointer to the new root after balancing
 */
avl_t *balance_avl(avl_t *tree, int value)
{
    int balance = binary_tree_balance(tree);

    /* Left Heavy */
    if (balance > 1)
    {
        if (value < tree->left->n)
            return (binary_tree_rotate_right(tree));
        tree->left = binary_tree_rotate_left(tree->left);
        return (binary_tree_rotate_right(tree));
    }

    /* Right Heavy */
    if (balance < -1)
    {
        if (value > tree->right->n)
            return (binary_tree_rotate_left(tree));
        tree->right = binary_tree_rotate_right(tree->right);
        return (binary_tree_rotate_left(tree));
    }

    return (tree);
}

/**
 * avl_insert_recursive - Recursively inserts a value into an AVL tree
 * @tree: Double pointer to the root node of the subtree
 * @parent: Pointer to the parent node
 * @new_node: Double pointer to store the newly created node
 * @value: Value to be inserted
 * Return: Pointer to the new root of the subtree
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent, avl_t **new_node, int value)
{
    if (*tree == NULL)
    {
        *new_node = *tree = binary_tree_node(parent, value);
        return (*tree);
    }

    if (value < (*tree)->n)
        (*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new_node, value);
    else if (value > (*tree)->n)
        (*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new_node, value);
    else
        return (*tree);

    return (balance_avl(*tree, value));
}

/**
 * avl_insert - Inserts a value in an AVL tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new_node = NULL;

    if (tree == NULL)
        return (NULL);

    avl_insert_recursive(tree, NULL, &new_node, value);
    return (new_node);
}
