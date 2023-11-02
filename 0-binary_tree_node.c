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
	binary_tree_t *new_root;

	new_root = malloc(sizeof(binary_tree_t));
	if (new_root == NULL)
		return (NULL);

	new_root->n = value;
	new_root->parent = parent;
	new_root->left = NULL;
	new_root->right = NULL;

	return (new_root);
}
