#include "binary_trees.h"
#include "0-binary_tree_node.c"

void pre_order(heap_t *tree, heap_t **node, size_t height);
void make_heap(heap_t *root);
size_t tree_height(const heap_t *tree);

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root of the heap.
 * Return: Value of the root node, or 0 if the heap is empty.
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *mbh, *new_node;

	if (!root || !*root)
		return (0);

	mbh = *root;
	value = mbh->n;

	if (!mbh->left && !mbh->right)
	{
		*root = NULL;
		free(mbh);
		return (value);
	}

	/* Find the last node using pre-order traversal */
	pre_order(mbh, &new_node, tree_height(mbh));

	/* Replace the root node's value with the last node's value */
	mbh->n = new_node->n;

	/* Remove the last node */
	if (new_node->parent->right)
		new_node->parent->right = NULL;
	else
		new_node->parent->left = NULL;

	free(new_node);

	/* Reorganize the tree to maintain max heap property */
	make_heap(mbh);

	*root = mbh;
	return (value);
}

/**
 * pre_order - Performs pre-order traversal to locate the last node.
 * @tree: Pointer to the root node of the tree.
 * @node: Pointer to store the last node found during traversal.
 * @height: Current height being traversed.
 */
void pre_order(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (height == 0)
		*node = tree;

	height--;

	pre_order(tree->left, node, height);
	pre_order(tree->right, node, height);
}

/**
 * make_heap - Restores max heap property by reorganizing the tree.
 * @root: Pointer to the root node of the binary heap.
 */
void make_heap(heap_t *root)
{
	heap_t *tmp_l, *tmp_r;
	int value;

	if (!root)
		return;

	tmp_l = root;

	while (1)
	{
		if (!tmp_l->left)
			break;

		if (!tmp_l->right)
			tmp_r = tmp_l->left;
		else
			tmp_r = (tmp_l->left->n > tmp_l->right->n) ? tmp_l->left : tmp_l->right;

		/* Swap parent and largest child if needed */
		if (tmp_l->n > tmp_r->n)
			break;

		value = tmp_l->n;
		tmp_l->n = tmp_r->n;
		tmp_r->n = value;

		tmp_l = tmp_r;
	}
}

/**
 * tree_height - Calculates the height of a binary tree.
 * @tree: Pointer to the root node of the tree.
 * Return: Height of the tree, or 0 if the tree is empty.
 */
size_t tree_height(const heap_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (!tree)
		return (0);

	/* Recursively calculate the height of left and right subtrees */
	if (tree->left)
		l_height = 1 + tree_height(tree->left);

	if (tree->right)
		r_height = 1 + tree_height(tree->right);

	/* Return the greater of the two subtree heights */
	return ((l_height > r_height) ? l_height : r_height);
}
