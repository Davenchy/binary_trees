#include "binary_trees.h"

/**
 * heapify_down - utility for building a heap array
 * @i: index of the node to heapify
 * @array: array
 * @size: size
 */
void heapify_down(int *array, int size, int i)
{
	int largest, left, right, tmp;

	largest = i;
	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		/*swap*/
		tmp = array[i];
		array[i] = array[largest];
		array[largest] = tmp;

		heapify_down(array, size, largest);
	}
}

/**
 * build_heap_graph - builds the graph of heap from its array representation
 * @arr_ptrs: array of pointers to the heap nodes
 * @size: size
 * @i: the index of the node to build
 */
void build_heap_graph(heap_t *arr_ptrs[], int i)
{
	int parent_index;

	parent_index = (i - 1) / 2;
	arr_ptrs[i]->parent = arr_ptrs[parent_index];

	if (i == (parent_index * 2) + 1)
	{
		arr_ptrs[parent_index]->left = arr_ptrs[i];
	}
	else
	{
		arr_ptrs[parent_index]->right = arr_ptrs[i];
	}
}

/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 * @array: is a pointer to the first element of the array to be converted
 * @size: is the number of element in the array
 *
 * Return: a pointer to the root node of the created Binary Heap, or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	int startIdx;
	heap_t **arr_ptrs;
	size_t i;

	/*
	 * No need to heapify down the leaves, as they already
	 * maintain the heap property
	 * Last non-leaf node = parent of last-node.
	 * or, Last non-leaf node = parent of node at (n-1)th index.
	 * or, Last non-leaf node = Node at index ((n-1) – 1)/2 = (n/2) – 1.
	 */
	startIdx = (size / 2) - 1;

	/*
	 * Perform reverse level order traversal
	 * from last non-leaf node and heapify
	 * each node
	 */
	for (i = startIdx; (int)i >= 0; i--)
	{
		heapify_down(array, size, i);
	}

	/*Build the heap graph from the array*/

	arr_ptrs = malloc(sizeof(heap_t *) * size);
	if (!arr_ptrs)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		arr_ptrs[i] = (heap_t *)binary_tree_node(NULL, array[i]);
	}

	arr_ptrs[0]->parent = NULL;
	for (i = 1; i < size; i++)
	{
		build_heap_graph(arr_ptrs, i);
	}

	return (arr_ptrs[0]);
}
