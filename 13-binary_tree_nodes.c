#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least one child
 * in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The number of nodes with at least one child.
 * If tree is NULL, return 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* A node has at least one child if it has a left or right child */
	if (tree->left != NULL || tree->right != NULL)
		return (1 + binary_tree_nodes(tree->left)
				+ binary_tree_nodes(tree->right));

	/* If the node has no children, return 0 */
	return (0);
}

