#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr, *new_node;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		if (new_node == NULL)
			return (NULL);
		*tree = new_node;
		return (new_node);
	}

	curr = *tree;
	while (curr != NULL)
	{
		if (value == curr->n)
			return (NULL);

		if (value < curr->n)
		{
			if (curr->left == NULL)
			{
				new_node = binary_tree_node(curr, value);
				curr->left = new_node;
				return (new_node);
			}
			curr = curr->left;
		}
		else
		{
			if (curr->right == NULL)
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
