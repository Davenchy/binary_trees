#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: a pointer to the node to insert the right-child in.
 * @value: the value to put in the new node.
 *
 * Return: a pointer to the new node, or NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* parent is required to insert nodes */
	if (!parent)
		return (NULL);

	/*allocate memory for a new node*/
	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;

	new_node->right = parent->right;

	if (parent->right) /*parent already has a right-child*/
	{
		/*
		 * the new node must take its place
		 * and the old right-child must be set as the right-child of the new node.
		 */
		parent->right->parent = new_node;
	}

	parent->right = new_node;

	return (new_node);
}
