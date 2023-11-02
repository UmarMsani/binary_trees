#include "binary_trees.h"

/**
 * binary_tree_height - Will Get the height of a binary tree
 * @tree: Is a Pointer to the root node of the tree
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_avl - will Checks if a binary tree is a valid AVL Tree
 * @tree: is a Pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (binary_tree_is_avl(tree->left) &&
			binary_tree_is_avl(tree->right));
}
