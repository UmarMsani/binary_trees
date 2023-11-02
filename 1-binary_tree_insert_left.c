#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as a left-child of
 *                           of another in binary tree.
 * @parent: is A pointer to the node to insert the left-child in.
 * @value: is The value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - A pointer to new node.
 * Description: if a parent already has left-child, new node
 *              takes its place and old left-child is set as
 *              the left-child of new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_root;

	if (parent == NULL)
		return (NULL);

	new_root = binary_tree_node(parent, value);
	if (new_root == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new_root->left = parent->left;
		parent->left->parent = new_root;
	}
	parent->left = new_root;

	return (new_root);
}
