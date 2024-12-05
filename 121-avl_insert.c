#include "binary_trees.h"

int get_balance(const binary_tree_t *tree);
avl_t *balance_avl_tree(avl_t **tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent, int value);

/**
 * get_balance - Calculates the balance factor of a binary tree
 * @tree: Pointer to the root of the tree
 * Return: Balance factor (height of left subtree - height of right subtree)
 */
int get_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = tree->left ? binary_tree_height(tree->left) : -1;
	right_height = tree->right ? binary_tree_height(tree->right) : -1;
	return (left_height - right_height);
}

/**
 * balance_avl_tree - Balances the AVL tree after insertion
 * @tree: Double pointer to the root of the tree
 * Return: Pointer to the new root after balancing
 */
avl_t *balance_avl_tree(avl_t **tree)
{
	int balance;

	if (tree == NULL || *tree == NULL)
		return (NULL);
	balance = get_balance(*tree);

	/* Left heavy */
	if (balance > 1)
	{
		/* Left-Right case */
		if (get_balance((*tree)->left) < 0)
			(*tree)->left = binary_tree_rotate_left((*tree)->left);

		/* Left-Left case */
		return (binary_tree_rotate_right(*tree));
	}

	/* Right heavy */
	if (balance < -1)
	{
		/* Right-Left case */
		if (get_balance((*tree)->right) > 0)
			(*tree)->right = binary_tree_rotate_right((*tree)->right);

		/* Right-Right case */
		return (binary_tree_rotate_left(*tree));
	}
	return (*tree);
}

/**
 * avl_insert_recursive - Recursively inserts a value into an AVL tree
 * @tree: Double pointer to the root of the tree
 * @parent: Parent of the current node
 * @value: Value to insert
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent, int value)
{
	avl_t *new_node;

	if (tree == NULL || *tree == NULL)
	{
		new_node = binary_tree_node(parent, value);
		return (new_node);
	}

	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert_recursive(&((*tree)->left), *tree, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert_recursive(&((*tree)->right), *tree, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (NULL); /* Duplicate value */

	/* Balance the tree after insertion */
	*tree = balance_avl_tree(tree);
	return (*tree);
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node;

	if (tree == NULL)
		return (NULL);

	/* If tree is empty, create root node */
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	/* Recursively insert and balance */
	new_node = avl_insert_recursive(tree, NULL, value);
	return (new_node);
}
