#include "binary_trees.h"
#include <stdio.h>

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

	left = tree->left ? binary_tree_height(tree->left) + 1 : 0;
	right = tree->right ? binary_tree_height(tree->right) + 1 : 0;
	return (left - right);
}
