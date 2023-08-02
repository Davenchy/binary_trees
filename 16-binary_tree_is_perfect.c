#include "binary_trees.h"

/**
 * tree_max_height - returns the max height of a binary tree
 * @tree: the pointer to the root node of the tree to check
 * Return: the max height
 */
static unsigned int tree_max_height(const binary_tree_t *tree)
{
	unsigned int left, right;

	if (!tree)
		return (0);

	left = tree_max_height(tree->left);
	right = tree_max_height(tree->right);

	return ((left > right ? left : right) + 1);
}

/**
 * tree_min_height - returns the min height of a binary tree
 * @tree: the pointer to the root node of the tree to check
 * Return: the min height
 */
static unsigned int tree_min_height(const binary_tree_t *tree)
{
	unsigned int left, right;

	if (!tree)
		return (0);

	left = tree_min_height(tree->left);
	right = tree_min_height(tree->right);

	return ((left < right ? left : right) + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: the pointer of the tree to check
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	unsigned int height, min_height;

	if (!tree)
		return (0);

	height = tree_max_height(tree);
	min_height = tree_min_height(tree);

	return (height == min_height);
}
