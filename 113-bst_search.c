#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree
 * @tree: Pointer to the root node of the BST to search
 * @value: Value to search in the tree
 *
 * Return: Pointer to the node containing a value equals to value,
 *         or NULL if tree is NULL or value is not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	/* Base case: if tree is NULL or value is found */
	if (tree == NULL || tree->n == value)
		return ((bst_t *)tree);

	/* If value is less than current node's value, search left subtree */
	if (value < tree->n)
		return (bst_search(tree->left, value));

	/* If value is greater than current node's value, search right subtree */
	return (bst_search(tree->right, value));
}
