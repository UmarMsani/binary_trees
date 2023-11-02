#include "binary_trees.h"

/**
 * bst_find_min - it will Finds the minimum value node in a BST
 * @node: is a Pointer to the root node of the BST
 *
 * Return: Pointer to the minimum value node
 */
bst_t *bst_find_min(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * bst_remove - will Removes a node from a Binary Search Tree
 * @value: is a Value to remove from the tree
 * @root: A Pointer to the root node of the tree
 *
 * Return: Pointer to the new root node after removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			bst_t *temp = root->right;

			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;

			free(root);
			return (temp);
		}

		bst_t *temp = bst_find_min(root->right);

		root->n = temp->n;

		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}
