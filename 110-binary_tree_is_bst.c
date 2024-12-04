#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst_helper - Helper function to check if a tree is a valid BST
 * @tree: Pointer to the current node in the tree
 * @min: Minimum allowable value for the current node
 * @max: Maximum allowable value for the current node
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);  /* NULL nodes are valid */

	if (tree->n <= min || tree->n >= max)
		return (0);  /* Violation of BST property */

	/* Check left subtree (values must be less than current node's value) */
	if (!is_bst_helper(tree->left, min, tree->n))
		return (0);

	/* Check right subtree (values must be greater than current node's value) */
	if (!is_bst_helper(tree->right, tree->n, max))
		return (0);

	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	/* Start the recursion with the full range of integer values */
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
