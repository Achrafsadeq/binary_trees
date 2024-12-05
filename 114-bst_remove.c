#include "binary_trees.h"
#include <stdlib.h>

bst_t *find_min_node(bst_t *node);

/**
 * find_min_node - Finds the node with the smallest value in a subtree
 * @node: Pointer to the root node of the subtree
 *
 * Return: Pointer to the node with the smallest value
 */
bst_t *find_min_node(bst_t *node)
{
	while (node && node->left)
		node = node->left;
	return (node);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree
 * @value: The value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL;

	if (!root)
		return (NULL);

	if (value < root->n) /* Traverse left subtree */
		root->left = bst_remove(root->left, value);
	else if (value > root->n) /* Traverse right subtree */
		root->right = bst_remove(root->right, value);
	else /* Node to be removed is found */
	{
		if (!root->left && !root->right) /* No children */
		{
			free(root);
			return (NULL);
		}
		else if (!root->left || !root->right) /* One child */
		{
			temp = root->left ? root->left : root->right;
			temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else /* Two children */
		{
			temp = find_min_node(root->right); /* In-order successor */
			root->n = temp->n; /* Replace value */
			root->right = bst_remove(root->right, temp->n); /* Remove successor */
		}
	}
	return (root);
}
