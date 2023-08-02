#include "binary_trees.h"

/**
 * has_node - Check if a sub-tree contains a node
 * @root: Pointer to the root node of the sub-tree
 * @node: Pointer to the node to check
 * Return: 1 if the node is in the sub-tree and 0 otherwise
 */
int has_node(binary_tree_t *root, binary_tree_t *node)
{
	if (root == NULL)
		return (0);
	if (root == node)
		return (1);
	return (has_node(root->right, node) || has_node(root->left, node));
}

/**
 * binary_trees_ancestor - finds the ancestor of a node
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
																		 const binary_tree_t *second)
{
	binary_tree_t *min = NULL, *max = NULL;

	if (!first || !second)
		return (NULL);

	max = (binary_tree_t *)(first->n > second->n ? first : second);
	min = (binary_tree_t *)(first->n > second->n ? second : first);

	while (min && min->parent && !has_node(min->parent, max))
		min = min->parent;

	return ((binary_tree_t *)min->parent);
}
