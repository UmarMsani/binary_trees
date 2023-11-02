#include "binary_trees.h"

/**
 * binary_tree_is_complete - It will Checks if a binary tree is complete
 * @tree: is a Pointer to the root node of the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int i;

	int nodes = 0, index = 0;

	if (!tree)
		return (0);

	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 4096);

	if (!queue)
		return (0);

	queue[0] = (binary_tree_t *)tree;

	while (index <= nodes)
	{
		if (queue[index])
		{
			nodes++;
			queue = realloc(queue, sizeof(binary_tree_t *) * (nodes * 2));

			if (!queue)
				return (0);
			queue[nodes * 2 - 1] = queue[index]->left;
			queue[nodes * 2] = queue[index]->right;
		}

		index++;
	}
	for (i = 0; i < index; i++)
	{
		if (!queue[i])
		{
			free(queue);
			return (0);
		}
	}
	free(queue);
	return (1);
}
