#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The size of the tree (number of nodes). If tree is NULL, return 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Size of tree is the root + size of left subtree + size of right subtree */
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
