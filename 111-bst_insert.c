#include "binary_trees.h"

bst_t *insert_leaf(bst_t **tree, int value)
{
	if (value < (*tree)->n)
	{
		if ((*tree)->left)
			return (insert_leaf(&((*tree)->left), value));
		else
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
	}

	if (value > (*tree)->n)
	{
		if ((*tree)->right)
			return (insert_leaf(&((*tree)->right), value));
		else
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
	}

	/*then value already exits -> ignore it*/
	return (NULL);
}

/**
 * bst_insert - inserts a value in a Binary Search Tree.
 * @tree: is a pointer to the root node of the BST to insert in
 * @value: is the value to insert in the tree
 *
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	return (insert_leaf(tree, value));
}
