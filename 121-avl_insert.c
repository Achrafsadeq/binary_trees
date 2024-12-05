#include "binary_trees.h"

avl_t *bst_insert(avl_t **tree, int value);
avl_t *balance_avl(avl_t **tree, int value);

/**
 * bst_insert - Helper function to insert a value in a BST fashion.
 * @tree: Double pointer to the root node of the tree.
 * @value: Value to insert.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
avl_t *bst_insert(avl_t **tree, int value)
{
	avl_t *new_node;

	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			new_node = binary_tree_node(*tree, value);
			(*tree)->left = new_node;
		}
		else
			new_node = bst_insert(&(*tree)->left, value);
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			new_node = binary_tree_node(*tree, value);
			(*tree)->right = new_node;
		}
		else
			new_node = bst_insert(&(*tree)->right, value);
	}
	else
		return (NULL); /* No duplicates allowed */

	return (new_node);
}

/**
 * balance_avl - Balances an AVL tree after insertion.
 * @tree: Double pointer to the root node of the tree.
 * @value: Value that was inserted.
 *
 * Return: Pointer to the root node after balancing.
 */
avl_t *balance_avl(avl_t **tree, int value)
{
	int balance = binary_tree_balance(*tree);

	if (balance > 1 && value < (*tree)->left->n)
		return (binary_tree_rotate_right(*tree));
	if (balance < -1 && value > (*tree)->right->n)
		return (binary_tree_rotate_left(*tree));
	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (binary_tree_rotate_right(*tree));
	}
	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (binary_tree_rotate_left(*tree));
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: Double pointer to the root node of the tree.
 * @value: Value to insert.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node;

	if (!tree)
		return (NULL);

	new_node = bst_insert(tree, value);
	if (!new_node)
		return (NULL);

	*tree = balance_avl(tree, value);

	return (new_node);
}

