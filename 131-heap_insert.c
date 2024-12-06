#include "binary_trees.h"
#include <stdlib.h>

/**
 * swap_values - Swaps the values of two nodes.
 * @node1: First node.
 * @node2: Second node.
 */
void swap_values(heap_t *node1, heap_t *node2)
{
	int temp = node1->n;

	node1->n = node2->n;
	node2->n = temp;
}

/**
 * bubble_up - Ensures the max heap property after insertion.
 * @node: Newly inserted node.
 */
void bubble_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap_values(node, node->parent);
		node = node->parent;
	}
}

/**
 * find_insert_position - Finds the next position to insert a node
 * using level order.
 * @root: Root of the heap.
 * Return: Pointer to the parent where the new node should be inserted.
 */
heap_t *find_insert_position(heap_t *root)
{
	heap_t **queue, *current;
	size_t front = 0, back = 0;

	queue = malloc(1024 * sizeof(heap_t *));
	if (!queue)
		return (NULL);

	queue[back++] = root;
	while (front < back)
	{
		current = queue[front++];
		if (!current->left || !current->right)
		{
			free(queue);
			return (current);
		}
		queue[back++] = current->left;
		queue[back++] = current->right;
	}

	free(queue);
	return (NULL);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * @value: Value to insert.
 * Return: Pointer to the newly created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *insert_position;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	insert_position = find_insert_position(*root);
	if (!insert_position)
		return (NULL);

	if (!insert_position->left)
		insert_position->left = binary_tree_node(insert_position, value);
	else
		insert_position->right = binary_tree_node(insert_position, value);

	new_node = insert_position->left ? insert_position->left
		: insert_position->right;
	bubble_up(new_node);

	return (new_node);
}
