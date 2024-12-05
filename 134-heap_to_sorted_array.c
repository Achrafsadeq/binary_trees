#include "binary_trees.h"
#include <stdlib.h>

size_t count_nodes(heap_t *root);

/**
 * count_nodes - Counts the number of nodes in a binary tree
 * @root: Pointer to the root node of the tree
 *
 * Return: Total number of nodes
 */
size_t count_nodes(heap_t *root)
{
	if (!root)
		return (0);
	return (1 + count_nodes(root->left) + count_nodes(root->right));
}

/**
 * heap_to_sorted_array - Converts a Max Binary Heap to a sorted array
 *                        of integers in descending order
 * @heap: Pointer to the root node of the heap
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t i, heap_size;

	if (!heap || !size)
		return (NULL);

	/* Count the number of nodes in the heap */
	heap_size = count_nodes(heap);
	*size = heap_size;

	/* Allocate memory for the array */
	array = malloc(heap_size * sizeof(int));
	if (!array)
		return (NULL);

	/* Extract the max element repeatedly and store in the array */
	for (i = 0; i < heap_size; i++)
		array[i] = heap_extract(&heap);

	return (array);
}
