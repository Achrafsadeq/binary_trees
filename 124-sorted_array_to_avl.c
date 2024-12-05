#include "binary_trees.h"

/**
 * avl_sa - Function that builds an AVL tree from an array
 * @root: Double pointer to root subtree
 * @array: Pointer to first element of array to be converted
 * @min: The lower bound index
 * @max: The upper bound index
 *
 * Return: None
 */
void avl_sa(avl_t **root, int *array, size_t min, size_t max)
{
	avl_t *new_node = NULL;
	size_t mid;

	/* Base case: if the subarray is invalid, return */
	if (min >= max)
		return;

	mid = (min + max) / 2;  /* Correct mid calculation */

	new_node = binary_tree_node(*root, array[mid]);
	if (!new_node)
		return;  /* Handle memory allocation failure */

	/* If the root is NULL, assign the new node as the root */
	if (*root == NULL)
		*root = new_node;
	else
	{
		/* If root node exists, determine whether to place the new node */
		if (array[mid] < (*root)->n)
			(*root)->left = new_node;
		else if (array[mid] > (*root)->n)
			(*root)->right = new_node;
	}

	/* Recursively build the left and right subtrees */
	avl_sa(&new_node, array, min, mid);  /* Left subtree */
	avl_sa(&new_node, array, mid + 1, max);  /* Right subtree */
}

/**
 * sorted_array_to_avl - Function that builds an AVL tree from an array
 * @array: Pointer to first element of array to be converted
 * @size: The size of the array
 *
 * Return: New node, NULL if otherwise
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *avl_tree = NULL;
	size_t mid;

	if (!array || size == 0)
		return (NULL);

	/* Start building the tree from the middle element */
	mid = size / 2;
	avl_tree = binary_tree_node(NULL, array[mid]);

	/* Recursively build left and right subtrees */
	avl_sa(&avl_tree, array, 0, mid);   /* Left subtree */
	avl_sa(&avl_tree, array, mid + 1, size);  /* Right subtree */

	return (avl_tree);
}
