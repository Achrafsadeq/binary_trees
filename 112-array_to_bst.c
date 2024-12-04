#include "binary_trees.h"

bst_t *bst_insert(bst_t **tree, int value);

/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST)
 * @tree: Pointer to the root of the tree
 * @value: The value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (!tree)
		return (NULL);

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
		return (bst_insert(&(*tree)->left, value));
	else if (value > (*tree)->n)
		return (bst_insert(&(*tree)->right, value));

	return (NULL);  /* Ignore duplicate values */
}

/**
 * array_to_bst - Builds a Binary Search Tree from an array
 * @array: Pointer to the array of integers
 * @size: The number of elements in the array
 *
 * Return: Pointer to the root of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i;

	for (i = 0; i < size; i++)
	{
		bst_insert(&tree, array[i]);
	}

	return (tree);
}
