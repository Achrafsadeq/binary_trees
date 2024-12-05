#include "binary_trees.h"

avl_t *insert(avl_t **tree, avl_t *parent, avl_t **new_node, int new_val);

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: Double pointer to the root node of the AVL tree.
 * @value: The integer value to be inserted into the new node.
 *
 * Description: This function handles AVL tree insertion and ensures that
 * the tree maintains its balanced property. It creates a new node if
 * necessary and uses a helper function to properly position it.
 *
 * Return: Pointer to the newly created node, or NULL if allocation fails.
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

	insert(tree, *tree, &new_node, value);
	return (new_node);
}

/**
 * insert - Helper function to insert a value in the AVL tree.
 * @tree: Double pointer to the root node of the tree.
 * @parent: Pointer to the parent node of the current subtree.
 * @new_node: Double pointer to store the address of the new node.
 * @new_val: The value to be inserted in the AVL tree.
 *
 * Description: Handles insertion of a new value into the correct position
 * in the tree. Adjusts tree balance using rotations when necessary to
 * ensure AVL property is maintained. Handles four rotation cases.
 *
 * Return: Pointer to the root of the updated tree, or NULL on failure.
 */
avl_t *insert(avl_t **tree, avl_t *parent, avl_t **new_node, int new_val)
{
	int bal_val;

	if (*tree == NULL)
		return (*new_node = binary_tree_node(parent, new_val));

	if ((*tree)->n > new_val)
	{
		(*tree)->left = insert(&(*tree)->left, *tree, new_node, new_val);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < new_val)
	{
		(*tree)->right = insert(&(*tree)->right, *tree, new_node, new_val);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	bal_val = binary_tree_balance(*tree);
	/* Handle Left-Left imbalance */
	if (bal_val > 1 && (*tree)->left->n > new_val)
		*tree = binary_tree_rotate_right(*tree);
	/* Handle Left-Right imbalance */
	else if (bal_val > 1 && (*tree)->left->n < new_val)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	/* Handle Right-Right imbalance */
	else if (bal_val < -1 && (*tree)->right->n < new_val)
		*tree = binary_tree_rotate_left(*tree);
	/* Handle Right-Left imbalance */
	else if (bal_val < -1 && (*tree)->right->n > new_val)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}
