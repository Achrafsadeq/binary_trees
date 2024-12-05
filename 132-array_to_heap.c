#include "binary_trees.h"

/**
 * array_to_heap - Converts an array to a Max Binary Heap tree
 * @array: Pointer to the first element of the array to convert
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created Binary Heap,
 * or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL; /* Root node of the heap */
	size_t index;        /* Index variable for array traversal */

	if (!array || size == 0)
		return (NULL);

	for (index = 0; index < size; index++)
	{
		if (!heap_insert(&root, array[index]))
		{
			/* Insertion failed, handle cleanup if necessary */
			return (NULL);
		}
	}

	return (root);
}
