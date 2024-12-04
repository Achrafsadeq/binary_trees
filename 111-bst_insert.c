#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: A double pointer to the root node of the BST
 * @value: The value to insert in the tree
 *
 * Return: A pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (!tree)
		return (NULL);

	/* If the tree is empty, create the root node */
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	/* Otherwise, traverse the tree to find the correct position */
	if (value < (*tree)->n)
	{
		if ((*tree)->left)
		{
			return (bst_insert(&(*tree)->left, value));
			}
		else
		{
			(*tree)->left = binary_tree_node(*tree, value);

			return ((*tree)->left);
		}
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right)
			{
			return (bst_insert(&(*tree)->right, value));
			}
		else
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
	}

	/* Return NULL if the value is already in the tree */
	return (NULL);
}
