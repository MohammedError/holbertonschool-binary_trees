#include "binary_trees.h"

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of the tree
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree == NULL)
		return (0);

	l = tree_height(tree->left);
	r = tree_height(tree->right);

	if (l > r)
		return (l + 1);
	return (r + 1);
}

/**
 * print_level - performs a function on a specific level of a binary tree
 * @tree: pointer to the root node of the tree
 * @level: level to perform the function on
 * @func: pointer to a function to call for each node
 */
void print_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_level(tree->left, level - 1, func);
		print_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - Level-order traversal of a binary tree
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, i;

	if (tree == NULL || func == NULL)
		return;

	h = tree_height(tree);

	for (i = 1; i <= h; i++)
		print_level(tree, i, func);
}
