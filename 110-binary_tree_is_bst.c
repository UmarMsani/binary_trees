#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst_util - Recursive function to check if a binary tree is a valid BST
 * @min: is a Minimum value for the node
 * @node: Is A Pointer to the current node
 * @max: is A Maximum value for the node
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_bst_util(const binary_tree_t *node, int min, int max)
{
	if (node == NULL)
		return (1);

	if (node->n < min || node->n > max)
		return (0);

	return (is_bst_util(node->left, min, node->n - 1) &&
			is_bst_util(node->right, node->n + 1, max));
}

/**
 * binary_tree_is_bst - It will Checks if a binary tree is a valid BST
 * @tree: is A Pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_util(tree, INT_MIN, INT_MAX));
}
