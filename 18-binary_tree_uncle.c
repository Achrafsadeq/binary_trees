#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a given node in a binary tree.
 * @node: Pointer to the node for which the uncle is to be located.
 *
 * Return: Pointer to the uncle node if it exists, otherwise NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* Check if the node, its parent, or grandparent is NULL */
	if (node == NULL || node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);

	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	return (node->parent->parent->left);
}

