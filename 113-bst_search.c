#include "binary_trees.h"

/**
 * bst_search - will Searches for a value in a Binary Search Tree
 * @value: is a Value to search in the tree
 * @tree: Is A Pointer to the root node of the BST to search
 *
 * Return: Pointer to node containing the value, or NULL if not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL || tree->n == value)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
}
