#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Tree to measure
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node
 * @i: Index of the node
 * @cnodes: Total number of nodes
 * Return: 1 if complete, 0 otherwise
 */
int tree_is_complete(const binary_tree_t *tree, int i, int cnodes)
{
	if (!tree)
		return (1);

	if (i >= cnodes)
		return (0);

	return (tree_is_complete(tree->left, (2 * i) + 1, cnodes) &&
		tree_is_complete(tree->right, (2 * i) + 2, cnodes));
}

/**
 * check_parent - Checks if parent value is greater than children
 * @tree: Pointer to the node to check
 * Return: 1 if parent is greater, 0 otherwise
 */
int check_parent(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree_is_complete(tree, 0, (int)binary_tree_size(tree)))
		return (0);

	if (tree->parent)
		return (check_parent(tree));

	return (check_parent(tree->left) && check_parent(tree->right));
}
