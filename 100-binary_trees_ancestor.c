#include "binary_trees.h"

/**
 * depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 *
 * Return: depth of the node
 */
size_t depth(const binary_tree_t *tree)
{
	size_t d = 0;

	while (tree->parent)
	{
		tree = tree->parent;
		d++;
	}
	return (d);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node, or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t d_f, d_s;

	if (!first || !second)
		return (NULL);

	d_f = depth(first);
	d_s = depth(second);

	while (d_f > d_s)
	{
		first = first->parent;
		d_f--;
	}
	while (d_s > d_f)
	{
		second = second->parent;
		d_s--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}
