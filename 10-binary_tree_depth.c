#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: a pointer to the node to measure the depth
 *
 * Return: the depth of a node, or 0 otherwise
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t counter = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		counter++;
		tree = tree->parent;
	}

	return (counter);
}
