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
 * heapify_up - Restores the max heap property by "bubbling up"
 * @node: Pointer to the newly inserted node
 *
 * Return: Pointer to the node after heapify
 */
heap_t *heapify_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap_values(node, node->parent);
		node = node->parent;
	}
	return (node);
}

/**
 * find_insertion_point - Finds the first available position for insertion
 *                        using level-order traversal
 * @root: Pointer to the root of the tree
 *
 * Return: Pointer to the parent node where the new node should be inserted
 */
heap_t *find_insertion_point(heap_t *root)
{
	queue_t *queue = queue_create();
	heap_t *current = NULL;

	if (!queue || !root)
		return (NULL);

	queue_enqueue(queue, root);

	while (!queue_is_empty(queue))
	{
		current = queue_dequeue(queue);

		if (!current->left || !current->right)
			break;

		queue_enqueue(queue, current->left);
		queue_enqueue(queue, current->right);
	}

	queue_free(queue);
	return (current);
}

/**
 * heap_insert - Inserts a value in a Max Binary Heap
 * @root: Double pointer to the root of the heap
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (!root)
		return (NULL);

	/* Create the root node if it doesn't exist */
	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	/* Find the insertion point */
	parent = find_insertion_point(*root);
	if (!parent)
		return (NULL);

	/* Insert the new node as a left or right child */
	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	/* Restore the max heap property */
	return (heapify_up(new_node));
}
