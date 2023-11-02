#include "binary_trees.h"

/**
 * find_successor - Will Finds the in-order successor of a node.
 * @node: is The node to find the successor for.
 *
 * Return: A pointer to the in-order successor node.
 */
static avl_t *find_successor(avl_t *node)
{
	avl_t *current = node->right;

	while (current->left != NULL)
		current = current->left;

	return (current);
}

/**
 * avl_remove - To Removes a node from an AVL Tree.
 * @value: is The value to remove.
 * @root: A pointer to root node of the AVL tree.
 *
 * Return: A pointer to the new root node of the tree after
 * removing the value, and after rebalancing.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			avl_t *temp = root->left ? root->left : root->right;
			*root = *temp;
			free(temp);
		}
		else
		{
			avl_t *temp = find_successor(root);

			root->n = temp->n;
			root->right = avl_remove(root->right, temp->n);
		}
	}

	if (!root)
		return (NULL);

	int balance = binary_tree_balance(root);

	if (balance > 1 && binary_tree_balance(root->left) >= 0)
		return (binary_tree_rotate_right(root));

	if (balance < -1 && binary_tree_balance(root->right) <= 0)
		return (binary_tree_rotate_left(root));

	if (balance > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}

	if (balance < -1 && binary_tree_balance(root->right) > 0)
	{
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}

	return (root);
}
