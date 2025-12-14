#include "binary_trees.h"

/**
 * successor - Get the next successor (min node in right subtree)
 * @node: Tree node
 * Return: pointer to the successor
 */
bst_t *successor(bst_t *node)
{
	bst_t *ptr = node;

	while (ptr->left)
		ptr = ptr->left;
	return (ptr);
}

/**
 * replace_two_children - Handles removal of a node with two children
 * @root: Pointer to the root
 * @node: Pointer to the node to delete
 * @succ: Pointer to the successor
 * Return: New root
 */
bst_t *replace_two_children(bst_t *root, bst_t *node, bst_t *succ)
{
	if (succ->parent != node)
	{
		succ->parent->left = succ->right;
		if (succ->right)
			succ->right->parent = succ->parent;
		succ->right = node->right;
		node->right->parent = succ;
	}
	succ->left = node->left;
	node->left->parent = succ;
	succ->parent = node->parent;
	if (node->parent)
	{
		if (node->parent->left == node)
			node->parent->left = succ;
		else
			node->parent->right = succ;
	}
	else
		root = succ;
	free(node);
	return (root);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = root, *parent, *succ;

	while (node)
	{
		if (node->n == value)
			break;
		node = (value < node->n) ? node->left : node->right;
	}
	if (!node)
		return (root);
	parent = node->parent;
	if (!node->left || !node->right)
	{
		succ = (node->left) ? node->left : node->right;
		if (parent)
			(parent->left == node) ? (parent->left = succ) : (parent->right = succ);
		else
			root = succ;
		if (succ)
			succ->parent = parent;
		free(node);
		return (root);
	}
	succ = successor(node->right);
	return (replace_two_children(root, node, succ));
}
