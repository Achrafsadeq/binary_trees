#include "binary_trees.h"

bst_t *find_successor(bst_t *node);
bst_t *replace_node(bst_t *root, bst_t *node);

/**
 * find_successor - Finds the in-order successor of a node
 * @node: Node to find successor for
 *
 * Return: Pointer to the in-order successor node
 */
bst_t *find_successor(bst_t *node)
{
	bst_t *current = node->right;

	while (current && current->left)
		current = current->left;

	return (current);
}

/**
 * replace_node - Replaces a node with its successor
 * @root: Root of the tree
 * @node: Node to be replaced
 *
 * Return: Pointer to the new node
 */
bst_t *replace_node(bst_t *root, bst_t *node)
{
	bst_t *successor = find_successor(node);
	bst_t *successor_child = NULL;

	/* Detach successor from its original position */
	if (successor->parent != node)
	{
		if (successor->right)
		{
			successor_child = successor->right;
			successor_child->parent = successor->parent;
		}
		successor->parent->left = successor_child;

		/* Connect successor to node's right subtree */
		successor->right = node->right;
		if (node->right)
			node->right->parent = successor;
	}

	/* Connect successor to node's left subtree */
	successor->left = node->left;
	if (node->left)
		node->left->parent = successor;

	/* Update parent connections */
	successor->parent = node->parent;
	if (!node->parent)
		root = successor;
	else if (node == node->parent->left)
		node->parent->left = successor;
	else
		node->parent->right = successor;

	/* Free the original node */
	free(node);

	return (root);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree
 * @value: Value to remove from the tree
 *
 * Return: Pointer to the new root node of the tree after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = root;

	while (node)
	{
		if (value == node->n)
			break;
		node = (value < node->n) ? node->left : node->right;
	}
	if (!node)
		return (root);
	if (!node->left && !node->right)
	{
		if (!node->parent)
		{
			free(node);
			return (NULL);/*return NULL*/}
		if (node->parent->left == node)
			node->parent->left = NULL;
		else
			node->parent->right = NULL;
		free(node);
		return (root);/*return root*/}
	if (!node->left || !node->right)
	{
		bst_t *child = node->left ? node->left : node->right;

		if (!node->parent)
		{
			child->parent = NULL;
			free(node);
			return (child);
		}
		if (node->parent->left == node)
			node->parent->left = child;
		else
			node->parent->right = child;
		child->parent = node->parent;
		free(node);
		return (root);
	}
	return (replace_node(root, node)); /*replace_node*/}
