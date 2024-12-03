#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to the uncle node, or NULL if no uncle exists
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* Check if node is NULL or if node has no parent or grandparent */
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	/* Get the grandparent */
	binary_tree_t *grandparent = node->parent->parent;

	/* If parent is left child, return right child of grandparent (uncle) */
	if (grandparent->left == node->parent)
		return (grandparent->right);

	/* If parent is right child, return left child of grandparent (uncle) */
	if (grandparent->right == node->parent)
		return (grandparent->left);

	return (NULL);
}
