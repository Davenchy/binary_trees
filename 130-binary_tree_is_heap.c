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
 * check_max_heap - checks heap max property
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 */
int check_max_heap(const binary_tree_t *tree)
{
	if (tree->left && tree->right)
	{
		if (tree->n < tree->left->n || tree->n < tree->right->n)
			return (0);

		return (check_max_heap(tree->left) && check_max_heap(tree->right));
	}
	else if (tree->left)
	{
		if (tree->n < tree->left->n)
			return (0);

		return (check_max_heap(tree->left));
	}

	return (1);
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0); /*Special Case*/

	if (!is_complete(tree, 0, binary_tree_size(tree)))
		return (0);

	return (check_max_heap(tree));
}
