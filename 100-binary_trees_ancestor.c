#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the ancestor of a node
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
																		 const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);
	else if (first->n == second->n)
		return ((binary_tree_t *) first);

	if (first->n > second->n)
	{
		if (second->parent)
			return (binary_trees_ancestor(first, second->parent));
		else
			return ((binary_tree_t *) second);
	}
	else if (first->n < second->n)
	{
		if (first->parent)
			return (binary_trees_ancestor(first->parent, second));
		else
			return ((binary_tree_t *) first);
	}

	return ((binary_tree_t *) first);
}
