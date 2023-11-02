#include "binary_trees.h"

/**
 * binary_tree_insert_right - will Insert a node as the right-child
 *                            of another in binary tree.
 * @value: is The value to store inside the new node.
 * @parent: is A pointer to node to be inserted the right-child in.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to new node.
 *
 * Description: If parent already has a right-child, the new node
 *              takes its place and the old right-child is set as
 *              the right-child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;

	return (new);
}
