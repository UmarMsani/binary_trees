#include "binary_trees.h"

/**
 * array_to_bst - To Builds a Binary Search Tree from an array
 * @size: is the Number of elements in the array
 * @array: Is A Pointer to the first element of the array
 *
 * Return: Pointer to root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	bst_t *root = NULL;

	for (size_t i = 0; i < size; i++)
	{
		if (bst_insert(&root, array[i]) == NULL)
		{
			return (NULL);
		}
	}

	return (root);
}
