#include "binary_trees.h"

/**
 * binary_tree_node - will Creates a binary tree node.
 * @value: The value to assigned or put in the new node.
 * @parent: A pointer to The parent of the node to create.
 *
 * Return: If An error occurs - NULL.
 *         Otherwise - a pointer to new node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
