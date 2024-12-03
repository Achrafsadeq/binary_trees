#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree
 * @node: Pointer to the node to find the uncle for
 *
 * Return: Pointer to the uncle node, or NULL if no uncle exists
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* If node is NULL or has no parent, return NULL */
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* If node's parent has no parent (grandparent), return NULL */
	if (node->parent->parent == NULL)
		return (NULL);

	/* Get the grandparent */
	binary_tree_t *grandparent = node->parent->parent;

	/* Determine the uncle */
	if (grandparent->left == node->parent)
		return (grandparent->right);
	else
		return (grandparent->left);
}
