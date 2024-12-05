#include "binary_trees.h"

/**
 * find_successor - Finds the inorder successor of a node
 * @node: Node to find the successor for
 * Return: Pointer to the successor node
 */
static avl_t *find_successor(avl_t *node)
{
    avl_t *current = node->right;
    
    while (current && current->left)
        current = current->left;
    
    return current;
}

/**
 * balance_check - Checks and restores AVL balance
 * @node: Node to check balance for
 * Return: Pointer to the root after balancing
 */
static avl_t *balance_check(avl_t *node)
{
    int balance;
    
    if (!node)
        return NULL;
        
    balance = binary_tree_balance(node);
    
    /* Left heavy */
    if (balance > 1) {
        if (binary_tree_balance(node->left) < 0)  /* Left-Right case */
            node->left = binary_tree_rotate_left(node->left);
        return binary_tree_rotate_right(node);
    }
    
    /* Right heavy */
    if (balance < -1) {
        if (binary_tree_balance(node->right) > 0)  /* Right-Left case */
            node->right = binary_tree_rotate_right(node->right);
        return binary_tree_rotate_left(node);
    }
    
    return node;
}

/**
 * avl_remove_recursive - Recursively removes a node from an AVL tree
 * @root: Pointer to the root node
 * @value: Value to remove
 * Return: Pointer to the root after removal
 */
static avl_t *avl_remove_recursive(avl_t *root, int value)
{
    avl_t *temp, *successor;
    
    if (!root)
        return NULL;
        
    /* Navigate to the node to delete */
    if (value < root->n)
        root->left = avl_remove_recursive(root->left, value);
    else if (value > root->n)
        root->right = avl_remove_recursive(root->right, value);
    else {
        /* Node with one child or no child */
        if (!root->left) {
            temp = root->right;
            if (temp)
                temp->parent = root->parent;
            free(root);
            return temp;
        }
        else if (!root->right) {
            temp = root->left;
            if (temp)
                temp->parent = root->parent;
            free(root);
            return temp;
        }
        
        /* Node with two children */
        successor = find_successor(root);
        root->n = successor->n;
        root->right = avl_remove_recursive(root->right, successor->n);
    }
    
    /* Rebalance the tree */
    return balance_check(root);
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree
 * @value: Value to remove
 * Return: Pointer to the new root node
 */
avl_t *avl_remove(avl_t *root, int value)
{
    avl_t *new_root = avl_remove_recursive(root, value);
    
    if (new_root)
        new_root->parent = NULL;
        
    return new_root;
}
