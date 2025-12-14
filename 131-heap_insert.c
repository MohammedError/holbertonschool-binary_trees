#include "binary_trees.h"

/**
 * heap_tree_size - Measures the size of a binary tree
 * @tree: Tree to measure
 * Return: Size of the tree
 */
size_t heap_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (heap_tree_size(tree->left) + heap_tree_size(tree->right) + 1);
}

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: Double pointer to the root node of the Heap to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new_node, *flip;
	size_t size, leaves, sub, bit, level, tmp;

	if (!root)
		return (NULL);
	if (!*root)
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = heap_tree_size(tree);
	leaves = size;
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;
	/* Subtract all nodes of full levels, leaves is now index in last level */

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;

	new_node = binary_tree_node(tree, value);
	if (leaves & 1)
		tree->right = new_node;
	else
		tree->left = new_node;

	flip = new_node;
	while (flip->parent && flip->n > flip->parent->n)
	{
		tmp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tmp;
		new_node = flip->parent;
		flip = flip->parent;
	}
	return (new_node);
}
