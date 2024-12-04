#include "binary_trees.h"
#include <stdlib.h>

bst_t *find_successor(bst_t *node);
bst_t *remove_leaf_node(bst_t *root, bst_t *node, bst_t *parent);
bst_t *remove_single_child_node(bst_t *root, bst_t *node, bst_t *parent);
bst_t *bst_remove_node(bst_t *root, bst_t *node);

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
 * remove_leaf_node - Handles removal of a leaf node
 * @root: Root of the tree
 * @node: Leaf node to remove
 * @parent: Parent of the node
 *
 * Return: Pointer to the new root node
 */
bst_t *remove_leaf_node(bst_t *root, bst_t *node, bst_t *parent)
{
	if (parent)
	{
		if (parent->left == node)
			parent->left = NULL;
		else
			parent->right = NULL;
	}
	else
		root = NULL;

	free(node);
	return (root);
}

/**
 * remove_single_child_node - Handles removal of a node with one child
 * @root: Root of the tree
 * @node: Node to remove
 * @parent: Parent of the node
 *
 * Return: Pointer to the new root node
 */
bst_t *remove_single_child_node(bst_t *root, bst_t *node, bst_t *parent)
{
	bst_t *child = node->left ? node->left : node->right;

	child->parent = parent;
	if (parent)
	{
		if (parent->left == node)
			parent->left = child;
		else
			parent->right = child;
	}
	else
		root = child;

	free(node);
	return (root);
}

/**
 * bst_remove_node - Removes a node from a Binary Search Tree
 * @root: Root of the tree
 * @node: Node to remove
 *
 * Return: Pointer to the new root node
 */
bst_t *bst_remove_node(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* Case 1: Node has no children (leaf) */
	if (!node->left && !node->right)
		return (remove_leaf_node(root, node, parent));

	/* Case 2: Node has only one child */
	if (!node->left || !node->right)
		return (remove_single_child_node(root, node, parent));

	/* Case 3: Node has two children - find in-order successor */
	successor = find_successor(node);
	node->n = successor->n;

	/* Recursively remove the successor */
	return (bst_remove_node(root, successor));
}

/**
 * bst_remove - Removes a node with a specific value from a Binary Search Tree
 * @root: Pointer to the root node of the tree
 * @value: Value to remove
 *
 * Return: Pointer to the new root node of the tree after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node_to_remove;

	if (!root)
		return (NULL);

	/* Find the node to remove */
	node_to_remove = bst_search(root, value);
	if (!node_to_remove)
		return (root);

	/* Remove the node and return the new root */
	return (bst_remove_node(root, node_to_remove));
}
