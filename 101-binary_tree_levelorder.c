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
 * print_lvl - prints a specific level of a binary tree.
 * @tree: the root of the tree.
 * @level_number: the number of the level to print.
 * @func: is a pointer to a function to call for each node.
 */
void print_lvl(const binary_tree_t *tree, int level_number, void (*func)(int))
{
	if (!tree | !func)
		return;

	if (level_number == 1)
		func(tree->n);
	else
	{
		print_lvl(tree->left, level_number - 1, func);
		print_lvl(tree->right, level_number - 1, func);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal - recursive implementation.
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (!tree || !func)
		return;

	height = recursive_tree_height(tree);
	for (i = 1; i <= height; i++)
	{
		print_level(tree, i, func);
	}
}
