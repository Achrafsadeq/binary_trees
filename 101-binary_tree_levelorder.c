#include "binary_trees.h"
#include <stdlib.h>

binary_tree_t *dequeue(binary_tree_t **queue, int *front);
void enqueue(binary_tree_t **queue, int *rear, binary_tree_t *node);

/**
 * enqueue - Adds a node to the queue.
 * @queue: The queue array.
 * @rear: Rear index of the queue.
 * @node: Node to add to the queue.
 */
void enqueue(binary_tree_t **queue, int *rear, binary_tree_t *node)
{
	queue[(*rear)++] = node;
}

/**
 * dequeue - Removes a node from the queue.
 * @queue: The queue array.
 * @front: Front index of the queue.
 *
 * Return: The dequeued node.
 */
binary_tree_t *dequeue(binary_tree_t **queue, int *front)
{
	return (queue[(*front)++]);
}

/**
 * binary_tree_levelorder - Performs level-order traversal of a binary tree.
 * @tree: Pointer to the root of the tree to traverse.
 * @func: Pointer to a function to call for each node's value.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue;
	int front = 0, rear = 0;
	size_t max_nodes;

	if (!tree || !func)
		return;

	/* Calculate the maximum number of nodes in the tree */
	max_nodes = 1024; /* Assumes a reasonable max size for simplicity */

	/* Allocate memory for the queue */
	queue = malloc(sizeof(binary_tree_t *) * max_nodes);
	if (!queue)
		return;

	/* Start with the root node in the queue */
	enqueue(queue, &rear, (binary_tree_t *)tree);

	/* Process nodes in the queue */
	while (front < rear)
	{
		binary_tree_t *node = dequeue(queue, &front);

		/* Process the current node */
		func(node->n);

		/* Enqueue the children of the current node */
		if (node->left)
			enqueue(queue, &rear, node->left);
		if (node->right)
			enqueue(queue, &rear, node->right);
	}

	free(queue);
}
