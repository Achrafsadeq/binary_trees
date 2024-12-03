#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, size;
	size_t perfect_size;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	size = binary_tree_size(tree);

	perfect_size = (1 << (height + 1)) - 1;
	return (size == perfect_size);
}
