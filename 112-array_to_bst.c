#include "binary_trees.h"
#include <stdlib.h>

/**
 * array_to_bst - Converts an array to a Binary Search Tree
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	/* Check for NULL array or zero size */
	if (array == NULL || size == 0)
		return (NULL);

	/* Insert each element of the array into the BST */
	for (i = 0; i < size; i++)
	{
		/* Ignore duplicate values */
		if (bst_insert(&root, array[i]) == NULL && root == NULL)
			return (NULL);
	}

	return (root);
}
