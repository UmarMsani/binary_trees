#include "binary_trees.h"

/**
 * binary_tree_is_complete - It will Checks if a binary tree is complete
 * @tree: is a Pointer to the root node of the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Initialize a queue for level order traversal */
	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1024);
	size_t front = 0, rear = 0;
	int flag = 0;

	/* Push the root to the queue */
	queue[rear++] = (binary_tree_t *)tree;

	/* Perform level order traversal */
	while (front < rear)
	{
		binary_tree_t *current = queue[front++];

		/* If we have encountered an empty node, set flag */
		if (current == NULL)
			flag = 1;
		else
		{
			/* If flag is set, the tree is not complete */
			if (flag)
			{
				free(queue);
				return (0);
			}

			/* Push left and right children to the queue */
			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}
	}

	free(queue);

	return (1);
}
