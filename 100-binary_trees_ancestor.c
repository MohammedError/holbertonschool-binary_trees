#include "binary_trees.h"

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
	size_t depth_f = 0, depth_s = 0;
	const binary_tree_t *tmp_f = first, *tmp_s = second;

	if (!first || !second)
		return (NULL);

	while (tmp_f->parent)
	{
		tmp_f = tmp_f->parent;
		depth_f++;
	}
	while (tmp_s->parent)
	{
		tmp_s = tmp_s->parent;
		depth_s++;
	}

	if (tmp_f != tmp_s)
		return (NULL);

	tmp_f = first;
	tmp_s = second;

	while (depth_f > depth_s)
	{
		tmp_f = tmp_f->parent;
		depth_f--;
	}
	while (depth_s > depth_f)
	{
		tmp_s = tmp_s->parent;
		depth_s--;
	}

	while (tmp_f && tmp_s)
	{
		if (tmp_f == tmp_s)
			return ((binary_tree_t *)tmp_f);
		tmp_f = tmp_f->parent;
		tmp_s = tmp_s->parent;
	}
	return (NULL);
}
