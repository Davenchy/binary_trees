#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure the size
 *
 * Return:the size of the tree, or 0 otherwise
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * is_complete - checks if a binary tree is complete
 * @tree: is a pointer to the root node of the tree to check
 * @index: index of the current node in the array repr
 * @size: number of nodes in the tree
 *
 * Return: 1 if true, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, int index, int size)
{
	if (!tree)
		return (1); /*Base Case*/

	/*
	 * If the index assigned to current node is more than
	 * number of nodes in tree, then tree is not complete
	 */
	if (index >= size)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, size) &&
			is_complete(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - calls for my is_complete function
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: 1 if true, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int nodes_number;

	if (!tree)
		return (0); /*Special Case*/

	nodes_number = binary_tree_size(tree);

	return (is_complete(tree, 0, nodes_number));
}
