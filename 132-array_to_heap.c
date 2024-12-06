#include "binary_trees.h"
#include <stdlib.h>

/**
 * array_to_heap - Builds a Max Binary Heap from an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root of the created Max Binary Heap,
 * or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t i;

	if (!array || size == 0)
		return (NULL);

	/* Create the heap by inserting nodes */
	for (i = 0; i < size; i++)
	{
		root = heap_insert(&root, array[i]);
		if (!root)
			return (NULL);
	}

	return (root);
}
