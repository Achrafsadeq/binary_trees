#include "binary_trees.h"

int successor(bst_t *node);
int remove_type(bst_t *root);
bst_t *remove_(bst_t *root, int value);
avl_t *avl_remove(avl_t *root, int value);

/**
 * avl_remove - Removes a node with a specific value from an AVL tree
 * @root: Pointer to the root of the AVL tree
 * @value: Value to remove from the tree
 *
 * Return: Pointer to the new root after removal
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *avl_root = (avl_t *)remove_((bst_t *)root, value);

	if (avl_root == NULL)
		return (NULL);

	avl_bal(&avl_root);
	return (avl_root);
}

/**
 * remove_ - Removes a node with a specific value from a binary search tree
 * @root: Pointer to the root of the tree
 * @value: Value to remove
 *
 * Return: Pointer to the root after removal
 */
bst_t *remove_(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		remove_(root->left, value);
	else if (value > root->n)
		remove_(root->right, value);
	else
	{
		type = remove_type(root);
		if (type != 0)
			remove_(root->right, type);
	}

	return (root);
}

/**
 * remove_type - Removes a node based on its children
 * @root: Pointer to the node to remove
 *
 * Return: The value of the successor or 0
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		else
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * successor - Finds the minimum value in the right subtree
 * @node: Pointer to the root of the subtree
 *
 * Return: Minimum value in the subtree
 */
int successor(bst_t *node)
{
	while (node->left)
		node = node->left;

	return (node->n);
}
