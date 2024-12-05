#include "binary_trees.h"

avl_t *find_min(avl_t *node);

/**
 * find_min - Finds the node with the smallest value in a subtree
 * @node: Pointer to the root of the subtree
 *
 * Return: Pointer to the node with the smallest value
 */
avl_t *find_min(avl_t *node)
{
	while (node && node->left)
		node = node->left;
	return (node);
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the AVL tree
 * @value: The value to remove from the tree
 *
 * Return: Pointer to the new root of the tree after removal
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp = NULL;

	if (!root)
		return (NULL);
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			temp = root->left ? root->left : root->right;
			free(root);
			return (temp);
		}
		else
		{
			temp = find_min(root->right);
			root->n = temp->n;
			root->right = avl_remove(root->right, temp->n);
		}
	}
	int balance = binary_tree_balance(root);

	if (balance > 1 && binary_tree_balance(root->left) >= 0)
		return (binary_tree_rotate_right(root));
	if (balance > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	if (balance < -1 && binary_tree_balance(root->right) <= 0)
		return (binary_tree_rotate_left(root));
	if (balance < -1 && binary_tree_balance(root->right) > 0)
	{
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
	return (root);
}
