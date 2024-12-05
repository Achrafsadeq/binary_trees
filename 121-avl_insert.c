#include "binary_trees.h"

/**
 * height - Compute the height of a node
 * @node: Pointer to the node
 * Return: Height of the node
 */
int height(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	return (1 + (height(node->left) > height(node->right) ?
		height(node->left) : height(node->right)));
}

/**
 * balance_factor - Calculate balance factor of a node
 * @node: Pointer to the node
 * Return: Balance factor
 */
int balance_factor(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	return (height(node->left) - height(node->right));
}

/**
 * perform_rotation - Perform appropriate rotation
 * @tree: Double pointer to root node
 * @value: Inserted value
 * Return: Pointer to new root
 */
avl_t *perform_rotation(avl_t **tree, int value)
{
	int bal = balance_factor(*tree);

	/* Left Heavy */
	if (bal > 1)
	{
		if (value < (*tree)->left->n)
			return (binary_tree_rotate_right(*tree));

		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (binary_tree_rotate_right(*tree));
	}

	/* Right Heavy */
	if (bal < -1)
	{
		if (value > (*tree)->right->n)
			return (binary_tree_rotate_left(*tree));

		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (binary_tree_rotate_left(*tree));
	}

	return (*tree);
}

/**
 * avl_recursive_insert - Recursively insert value in AVL tree
 * @tree: Double pointer to root node
 * @parent: Parent of current node
 * @new_node: Pointer to store new node
 * @value: Value to insert
 * Return: Pointer to root node
 */
avl_t *avl_recursive_insert(avl_t **tree, avl_t *parent,
		avl_t **new_node, int value)
{
	if (*tree == NULL)
	{
		*new_node = binary_tree_node(parent, value);
		return (*new_node);
	}

	if (value < (*tree)->n)
	{
		(*tree)->left = avl_recursive_insert(&(*tree)->left,
				*tree, new_node, value);
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_recursive_insert(&(*tree)->right,
				*tree, new_node, value);
	}
	else
		return (*tree);

	return (perform_rotation(tree, value));
}

/**
 * avl_insert - Insert value in AVL tree
 * @tree: Double pointer to root node
 * @value: Value to insert
 * Return: Created node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	avl_recursive_insert(tree, NULL, &new_node, value);
	return (new_node);
}
