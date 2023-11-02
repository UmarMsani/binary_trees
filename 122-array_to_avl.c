#include "binary_trees.h"

/**
 * array_to_avl - To Builds an AVL tree from an array
 * @size: is a Number of elements in the array
 * @array: A Pointer to first element of the array to be converted
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t x, y;

	if (array == NULL)
		return (NULL);

	for (x = 0; x < size; x++)
	{
		for (y = 0; y < x; y++)
		{
			if (array[y] == array[x])
				break;
		}
		if (y == x)
		{
			if (avl_insert(&root, array[x]) == NULL)
				return (NULL);
		}
	}

	return (root);
}
