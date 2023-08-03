#include "binary_trees.h"

/**
 * check_ancestors - checks whether the node maintains
 * the bst prperty with its ancestors
 * @tree: pointer to the node
 *
 * Return: 1 if true, 0 otherwise
 */
int check_ancestors(const binary_tree_t *tree)
{
	binary_tree_t *p, *gp;

	if (!tree || !tree->parent || !tree->parent->parent)
		return (1);

	p = tree->parent;
	gp = p->parent;

	while (p && gp)
	{
		if (p->n < gp->n && tree->n >= gp->n)
			return (0);

		if (p->n > gp->n && tree->n <= gp->n)
			return (0);

		p = p->parent;
		gp = p->parent;
	}

	return (1);
}

/**
 * is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->left && tree->left->n >= tree->n)
		return (0);

	if (tree->right && tree->right->n <= tree->n)
		return (0);

	if (!check_ancestors(tree->left) || !check_ancestors(tree->right))
		return (0);

	return (is_bst(tree->left) && is_bst(tree->right));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst(tree));
}
