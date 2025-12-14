#include "binary_trees.h"

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node of the tree after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = root, *parent, *successor;

	if (!root)
		return (NULL);
	/* Find node */
	while (node)
	{
		if (node->n == value)
			break;
		node = (value < node->n) ? node->left : node->right;
	}
	if (!node)
		return (root);
	
	parent = node->parent;
	
	/* Case: 0 or 1 child */
	if (!node->left || !node->right)
	{
		successor = (node->left) ? node->left : node->right;
		if (parent)
			(parent->left == node) ? (parent->left = successor) : (parent->right = successor);
		else
			root = successor;
		if (successor)
			successor->parent = parent;
		free(node);
		return (root);
	}
	
	/* Case: 2 children - Find in-order successor */
	successor = node->right;
	while (successor->left)
		successor = successor->left;
	
	/* Update successor links if not direct child */
	if (successor->parent != node)
	{
		successor->parent->left = successor->right;
		if (successor->right)
			successor->right->parent = successor->parent;
		successor->right = node->right;
		node->right->parent = successor;
	}
	
	successor->left = node->left;
	node->left->parent = successor;
	successor->parent = node->parent;
	
	if (parent)
		(parent->left == node) ? (parent->left = successor) : (parent->right = successor);
	else
		root = successor;
	
	free(node);
	return (root);
}
