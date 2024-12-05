#include "binary_trees.h"
#include <stdlib.h>

/**
 * heapify_up - Restores the max heap property by "bubbling up"
 * @node: Pointer to the newly inserted node
 *
 * Return: Pointer to the node after heapify
 */
heap_t *heapify_up(heap_t *node)
{
	heap_t *parent;
	int temp;

	if (!node || !node->parent)
		return (node);

	parent = node->parent;

	/* Swap if the parent is smaller than the current node */
	if (parent->n < node->n)
	{
		temp = parent->n;
		parent->n = node->n;
		node->n = temp;
		return (heapify_up(parent));
	}

	return (node);
}

/**
 * insert_node_level_order - Inserts a node into the first available position
 *                           in level order
 * @root: Pointer to the root of the heap
 * @value: Value to insert
 *
 * Return: Pointer to the newly inserted node, or NULL on failure
 */
heap_t *insert_node_level_order(heap_t *root, int value)
{
	heap_t *new_node = NULL;
	queue_t *queue = NULL, *current;

	/* Level-order traversal using a queue */
	queue = queue_create(root);
	while (queue)
	{
		current = queue_dequeue(&queue);

		/* Insert the new node as a left or right child */
		if (!current->node->left)
		{
			current->node->left = binary_tree_node(current->node, value);
			new_node = current->node->left;
			break;
		}
		else if (!current->node->right)
		{
			current->node->right = binary_tree_node(current->node, value);
			new_node = current->node->right;
			break;
		}

		/* Add the children to the queue */
		queue_enqueue(&queue, current->node->left);
		queue_enqueue(&queue, current->node->right);
	}

	free_queue(queue);
	return (new_node);
}

/**
 * heap_insert - Inserts a value in Max Binary Heap
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

	/* If the heap is empty, create the root node */
	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	/* Insert the node at the first available position */
	new_node = insert_node_level_order(*root, value);
	if (!new_node)
		return (NULL);

	/* Restore the max heap property */
	return (heapify_up(new_node));
}
