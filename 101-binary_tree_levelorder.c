#include "binary_trees.h"

/**
 * binary_tree_levelorder - it Traverse binary tree using level-order traversal
 * @func: Is a Pointer to a function to call for each node
 * @tree: is a Pointer to the root node of the tree to traverse
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 4096);
	size_t front = 0, rear = 0;
	binary_tree_t *temp = (binary_tree_t *)tree;

	while (temp)
	{
		func(temp->n);

		if (temp->left)
			queue[rear++] = temp->left;
		if (temp->right)
			queue[rear++] = temp->right;

		if (front == rear)
			break;

		temp = queue[front++];
	}

	free(queue);
}
