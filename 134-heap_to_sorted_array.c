#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: Size or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	height_l = tree ? tree_size(tree->left) : 0;
	height_r = tree ? tree_size(tree->right) : 0;
	return (height_l + height_r + 1);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array
 * @heap: pointer to the root node of the heap to convert
 * @size: an address to store the size of the array
 *
 * Return: pointer to the generated array, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	int extract;
	size_t i = 0, s;

	if (!heap || !size)
		return (NULL);

	s = tree_size(heap);
	*size = s;

	array = malloc(sizeof(int) * s);
	if (!array)
		return (NULL);

	for (i = 0; i < s; i++)
	{
		extract = heap_extract(&heap);
		array[i] = extract;
	}

	return (array);
}
