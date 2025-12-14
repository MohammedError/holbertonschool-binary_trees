#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_size_h - Measures the size of a binary tree
 * @tree: Tree to measure
 * Return: Size of the tree
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (tree_size_h(tree->left) + tree_size_h(tree->right) + 1);
}

/**
 * _recurse_heapify - Restores the Max Heap property by swapping down
 * @root: Pointer to the node to start heapifying from
 */
void _recurse_heapify(heap_t *root)
{
	heap_t *largest = root;
	int temp;

	if (!root)
		return;

	if (root->left && root->left->n > largest->n)
		largest = root->left;
	if (root->right && root->right->n > largest->n)
		largest = root->right;

	if (largest != root)
	{
		temp = root->n;
		root->n = largest->n;
		largest->n = temp;
		_recurse_heapify(largest);
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of heap
 *
 * Return: The value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_r, *node;
	size_t size, bit;

	if (!root || !*root)
		return (0);

	heap_r = *root;
	value = heap_r->n;
	size = tree_size_h(heap_r);

	if (size == 1)
	{
		free(heap_r);
		*root = NULL;
		return (value);
	}

	for (bit = 1; bit <= size; bit <<= 1)
		;
	bit >>= 2;

	node = heap_r;
	while (bit > 0)
	{
		node = (size & bit) ? node->right : node->left;
		bit >>= 1;
	}

	heap_r->n = node->n;
	if (node->parent->left == node)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;
	free(node);

	_recurse_heapify(heap_r);
	return (value);
}
