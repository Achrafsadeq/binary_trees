#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if none
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	/* Temporary pointer to traverse the second node's ancestors */
	const binary_tree_t *temp;

	if (!first || !second)
		return (NULL);

	/* Traverse the first node's ancestors and mark them */
	while (first)
	{
		temp = second;
		/* Traverse the second node's ancestors to find a match */
		while (temp)
		{
			if (first == temp)
				return ((binary_tree_t *)first);
			temp = temp->parent;
		}
		first = first->parent;
	}
	return (NULL);
}
