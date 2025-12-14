#include "binary_trees.h"
#include <limits.h>

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: Height of the tree
 */
size_t height(const binary_tree_t *tree)
{
	size_t l, r;

	if (!tree)
		return (0);
	l = height(tree->left);
	r = height(tree->right);
	return (1 + (l > r ? l : r));
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 * @min: Lower bound for the node's value
 * @max: Upper bound for the node's value
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	size_t h_l, h_r;
	int diff;

	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	h_l = height(tree->left);
	h_r = height(tree->right);
	diff = h_l > h_r ? h_l - h_r : h_r - h_l;

	if (diff > 1)
		return (0);

	return (is_avl_helper(tree->left, min, tree->n) &&
		is_avl_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
