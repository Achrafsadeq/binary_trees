#include "binary_trees.h"
#include <stdlib.h>
#include <limits.h>

int height(const binary_tree_t *tree);
int is_bst(const binary_tree_t *tree, int min, int max);
int is_avl(const binary_tree_t *tree, int *height_diff);

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value allowed in the tree
 * @max: Maximum value allowed in the tree
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst(tree->left, min, tree->n) &&
		is_bst(tree->right, tree->n, max));
}

/**
 * is_avl - Recursively checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 * @height_diff: Pointer to store the height of the current tree
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int is_avl(const binary_tree_t *tree, int *height_diff)
{
	int left_height = 0, right_height = 0;

	if (!tree)
	{
		*height_diff = 0;
		return (1);
	}

	if (!is_avl(tree->left, &left_height) ||
		!is_avl(tree->right, &right_height))
		return (0);

	*height_diff = 1 + (left_height > right_height ? left_height : right_height);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height_diff = 0;

	if (!tree)
		return (0);

	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	return (is_avl(tree, &height_diff));
}
