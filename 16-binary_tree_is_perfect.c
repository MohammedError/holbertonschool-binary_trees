#include "binary_trees.h"

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height or 0 if tree is NULL
 */
int tree_height(const binary_tree_t *tree)
{
	int l, r;

	if (tree == NULL)
		return (-1);

	l = tree_height(tree->left);
	r = tree_height(tree->right);

	if (l > r)
		return (l + 1);
	return (r + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int l_height, r_height;

	if (tree == NULL)
		return (0);

	l_height = tree_height(tree->left);
	r_height = tree_height(tree->right);

	if (l_height == r_height)
	{
		if (tree->left == NULL && tree->right == NULL)
			return (1);

		if (tree->left && tree->right)
			return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	}

	return (0);
}
