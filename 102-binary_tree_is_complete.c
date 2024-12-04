#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue;
	int front = 0, rear = 0;
	size_t max_nodes;
	int found_incomplete = 0;

	if (!tree)
		return (0);
	max_nodes = 1024; /* Assume a reasonable maximum size */
	queue = malloc(sizeof(binary_tree_t *) * max_nodes);
	if (!queue)
		return (0);
	queue[rear++] = (binary_tree_t *)tree;
	while (front < rear)
	{
		binary_tree_t *node = queue[front++];

		if (node->left)
		{
			if (found_incomplete)
			{
				free(queue);
				return (0); /* Incomplete node followed by a non-NULL child */
			}
			queue[rear++] = node->left;
		}
		else
			found_incomplete = 1;
		if (node->right)
		{
			if (found_incomplete)
			{
				free(queue);
				return (0); /* Incomplete node followed by a non-NULL child */
			}
			queue[rear++] = node->right;
		}
		else
			found_incomplete = 1;
	}
	free(queue);
	return (1); /* If traversal completes without issue, tree is complete */}
