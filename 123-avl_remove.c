#include "binary_trees.h"
#include <stdlib.h>

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
 * rebalance - Rebalances the AVL tree after deletion
 * @tree: Pointer to the root node of the tree
 *
 * Return: Pointer to the new root of the tree
 */
avl_t *rebalance(avl_t *tree)
{
	int balance;

	if (!tree)
		return (NULL);

	balance = binary_tree_balance(tree);

	/* Left-Left case */
	if (balance > 1 && binary_tree_balance(tree->left) >= 0)
		return (binary_tree_rotate_right(tree));

	/* Left-Right case */
	if (balance > 1 && binary_tree_balance(tree->left) < 0) {
		tree->left = binary_tree_rotate_left(tree->left);
		return (binary_tree_rotate_right(tree));
	}

	/* Right-Right case */
	if (balance < -1 && binary_tree_balance(tree->right) <= 0)
		return (binary_tree_rotate_left(tree));

	/* Right-Left case */
	if (balance < -1 && binary_tree_balance(tree->right) > 0) {
		tree->right = binary_tree_rotate_right(tree->right);
		return (binary_tree_rotate_left(tree));
	}

	return (tree);
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree
 * @value: Value to remove from the tree
 *
 * Return: Pointer to the new root node of the tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp = NULL;

	if (!root)
		return (NULL);

	/* Navigate the tree to find the node to delete */
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else {
		/* Node to be deleted found */
		if (!root->left) {
			temp = root->right;
			free(root);
			return (temp);
		} else if (!root->right) {
			temp = root->left;
			free(root);
			return (temp);
		}

		/* Node with two children: replace with in-order successor */
		temp = find_min(root->right);
		root->n = temp->n;
		root->right = avl_remove(root->right, temp->n);
	}

	/* Rebalance the tree */
	return (rebalance(root));
}
