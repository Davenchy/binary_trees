#include "binary_trees.h"


/**
 * recursive_tree_height - measures the height of a binary tree + 1.
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: the height of the binary tree rooted at `tree` + 1, or 0 otherwise
 */
size_t recursive_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);

	left_height = recursive_tree_height(tree->left);
	right_height = recursive_tree_height(tree->right);

	if (left_height > right_height)
	{
		return (left_height + 1);
	}

	return (right_height + 1);
}

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: the height of the binary tree rooted at `tree`, or 0 otherwise
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (recursive_tree_height(tree) - 1);
}
