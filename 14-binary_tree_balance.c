#include "binary_trees.h"

/**
 * height - measures the height of a binary tree
 * @tree: pointer to the starting node
 * Return: the height
 */
static unsigned int height(const binary_tree_t *tree)
{
	unsigned int l, r;

	if (!tree)
		return (0);

	l = height(tree->left);
	r = height(tree->right);

	return ((l > r ? l : r) + 1);
}

/**
 * binary_tree_balance - measures the balance of a binary tree
 * @tree: pointer to the root node of the tree to measure
 * Return: the balance of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);

	left = tree->left ? height(tree->left) : 0;
	right = tree->right ? height(tree->right) : 0;
	return (left - right);
}
