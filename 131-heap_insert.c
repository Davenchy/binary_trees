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
 * heap_to_array - build array representation of a heap
 */
void heap_to_array(heap_t **node, int index, int *array)
{
	if (*node == NULL)
		return;
	array[index] = (*node)->n;
	heap_to_array(&((*node)->left), 2 * index + 1, array);
	heap_to_array(&((*node)->right), 2 * index + 2, array);
}

/**
 * heapify_up - when a new node is inserted to a heap,
 * it puts it in the right place
 */
void heapify_up(int child_pos, int *array, int size)
{
	int par_pos, tmp;

	par_pos = (child_pos - 1) / 2;

	if (child_pos == 0 || array[child_pos] <= array[par_pos])
		return;

	/*swap*/
	tmp = array[child_pos];
	array[child_pos] = array[par_pos];
	array[par_pos] = tmp;

	heapify_up(par_pos, array, size);
}

/**
 * free_heap - free the heap nodes
 * @root: pointer to the root of the heap
*/
void free_heap(heap_t *root)
{
	if (!root)
		return;
	free(root->left);
	free(root->right);
	free(root);
}

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: is a double pointer to the root node of the Heap to insert the value
 * @value: is the value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	size_t size;
	int *array;
	heap_t *new_heap;

	if (!(*root))
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = binary_tree_size(*root);
	array = malloc(sizeof(int) * (size + 1));
	if (!array)
		return (NULL);

	heap_to_array(root, 0, array);

	array[size++] = value;

	heapify_up(size - 1, array, size);

	/*build the heap from the array again*/
	new_heap = array_to_heap(array, size);

	free_heap(*root);

	return (new_heap);
}
