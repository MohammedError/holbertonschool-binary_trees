#include "binary_trees.h"

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr, *new_node;

	if (!tree)
		return (NULL);

	if (!*tree)
	{
		new_node = binary_tree_node(NULL, value);
		if (!new_node)
			return (NULL);
		*tree = new_node;
		return (new_node);
	}

	curr = *tree;
	while (curr)
	{
		if (value == curr->n)
			return (NULL);

		if (value < curr->n)
		{
			if (!curr->left)
			{
				new_node = binary_tree_node(curr, value);
				curr->left = new_node;
				return (new_node);
			}
			curr = curr->left;
		}
		else
		{
			if (!curr->right)
			{
				new_node = binary_tree_node(curr, value);
				curr->right = new_node;
				return (new_node);
			}
			curr = curr->right;
		}
	}
	return (NULL);
}
