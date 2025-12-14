#include "binary_trees.h"

/**
 * bal - Measures balance factor of a binary tree and balances it
 * @tree: Double pointer to the node to balance
 */
void bal(avl_t **tree)
{
	int bval;

	if (tree == NULL || *tree == NULL)
		return;

	bval = binary_tree_balance(*tree);
	if (bval > 1 && binary_tree_balance((*tree)->left) >= 0)
		*tree = binary_tree_rotate_right(*tree);
	else if (bval > 1 && binary_tree_balance((*tree)->left) < 0)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bval < -1 && binary_tree_balance((*tree)->right) <= 0)
		*tree = binary_tree_rotate_left(*tree);
	else if (bval < -1 && binary_tree_balance((*tree)->right) > 0)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
}

/**
 * avl_remove - removes a node from an AVL tree
 * @root: pointer to the root node of the tree for removing a node
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node of the tree after removing the value
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			temp = root->left ? root->left : root->right;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		temp = root->right;
		while (temp->left)
			temp = temp->left;
		root->n = temp->n;
		root->right = avl_remove(root->right, temp->n);
	}
	bal(&root);
	return (root);
}
