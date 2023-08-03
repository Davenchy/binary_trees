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
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *ptr = NULL;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	ptr = (binary_tree_t *)first;
	while (ptr && ptr->parent && !has_node(ptr->parent, (binary_tree_t *)second))
		ptr = ptr->parent;

	return ((binary_tree_t *)ptr ? ptr->parent : NULL);
}
