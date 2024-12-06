#include "binary_trees.h"
#include <stdlib.h>

/**
 * swap_values - Swaps the values of two nodes
 * @node1: Pointer to the first node
 * @node2: Pointer to the second node
 */
void swap_values(heap_t *node1, heap_t *node2)
{
	int temp;

	temp = node1->n;
	node1->n = node2->n;
	node2->n = temp;
}

/**
 * heapify_up - Restores the Max-Heap property after insertion
 * @node: Pointer to the newly inserted node
 */
void heapify_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap_values(node, node->parent);
		node = node->parent;
	}
}

/**
 * insert_node - Helper function to perform level-order insertion
 * @root: Pointer to the root of the heap
 * @value: Value to insert
 *
 * Return: Pointer to the newly created node
 */
heap_t *insert_node(heap_t *root, int value)
{
	heap_t *new_node = NULL;
	heap_t **queue;
	size_t front = 0, back = 0;

	/* Create a queue for level-order traversal */
	queue = malloc(sizeof(heap_t *) * 1024);
	if (!queue)
		return (NULL);
	queue[back++] = root;

	/* Perform level-order traversal to find the first empty spot */
	while (front < back)
	{
		heap_t *current = queue[front++];

		if (!current->left)
		{
			new_node = binary_tree_node(current, value);
			current->left = new_node;
			break;
		}
		queue[back++] = current->left;

		if (!current->right)
		{
			new_node = binary_tree_node(current, value);
			current->right = new_node;
			break;
		}
		queue[back++] = current->right;
	}

	free(queue);
	return (new_node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root of the heap
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (!root)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	/* Insert the node and restore the Max-Heap property */
	new_node = insert_node(*root, value);
	if (!new_node)
		return (NULL);

	heapify_up(new_node);
	return (new_node);
}
