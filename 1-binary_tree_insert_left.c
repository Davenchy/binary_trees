#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node.
 * @parent: a pointer to the node to insert the left-child in.
 * @value: the value to put in the new node.
 *
 * Return: a pointer to the new node, or NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/*allocate memory for a new node*/
	new_node = malloc(sizeof(binary_tree_t));

	if (!new_node || !parent)
	{
		/*malloc failed or parent is NULL*/
		return (NULL);
	}

	new_node->n = value;
	new_node->parent = parent;

	if (parent->left) /*parent already has a left-child*/
	{
		/*
		* the new node must take its place
		* and the old left-child must be set as the left-child of the new node.
		*/
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}

	parent->left = new_node;
	new_node->right = NULL;

	return (new_node);
}