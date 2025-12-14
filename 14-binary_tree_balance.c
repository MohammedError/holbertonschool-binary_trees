#include "binary_trees.h"

/**
 * binary_tree_height_b - Measures height of a binary tree for a bal factor
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree + 1, or 0 if tree is NULL
 */
size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree == NULL)
		return (0);

	l = binary_tree_height_b(tree->left);
	r = binary_tree_height_b(tree->right);

	if (l >= r)
		return (1 + l);

	return (1 + r);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: Balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return ((int)binary_tree_height_b(tree->left) -
		(int)binary_tree_height_b(tree->right));
}
