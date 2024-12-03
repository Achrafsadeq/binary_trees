#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The number of leaves in the tree. If tree is NULL, return 0.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* A leaf is a node with no children (both left and right are NULL) */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* Recursively count leaves in both left and right subtrees */
	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
