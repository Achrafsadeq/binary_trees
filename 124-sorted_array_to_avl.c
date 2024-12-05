#include "binary_trees.h"
#include <stddef.h>

/**
 * create_avl_tree - Helper function to create an AVL tree
 * @array: Pointer to the first element of the array
 * @start: Starting index of the subarray
 * @end: Ending index of the subarray
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the created AVL node
 */
avl_t *create_avl_tree(int *array, size_t start, size_t end, avl_t *parent)
{
	size_t mid;
	avl_t *node;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	node = binary_tree_node(parent, array[mid]);
	if (!node)
		return (NULL);

	node->left = create_avl_tree(array, start, mid - 1, node);
	node->right = create_avl_tree(array, mid + 1, end, node);

	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (create_avl_tree(array, 0, size - 1, NULL));
}
