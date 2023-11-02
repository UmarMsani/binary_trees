#include "binary_trees.h"

int is_avl_helper(const binary_tree_t *node, int min, int max);

/**
 * binary_tree_is_avl - To Checks if binary tree is a valid AVL Tree
 * @tree: is A pointer to root node of the tree to check.
 *
 * Return: 1 if the tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_avl_helper - Recursive helper function to check if tree is valid AVL Tree
 * @max: Is a Maximum valid value for the current node.
 * @node: is a Current node being checked.
 * @min: is a Minimum valid value for the current node.
 *
 * Return: 1 if the subtree is a valid AVL Tree, 0 otherwise.
 */
int is_avl_helper(const binary_tree_t *node, int min, int max)
{
	int left_height, right_height, balance;

	if (node == NULL)
		return (1);

	if (node->n <= min || node->n >= max)
		return (0);

	left_height = binary_tree_height(node->left);
	right_height = binary_tree_height(node->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	balance = binary_tree_balance(node);

	if (balance < -1 || balance > 1)
		return (0);

	return (is_avl_helper(node->left, min, node->n) &&
			is_avl_helper(node->right, node->n, max));
}

/**
 * binary_tree_height -To  Measures the height of a binary tree.
 * @tree: is A pointer to the root node of the tree to measure.
 *
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_balance - will Measures the balance factor of a binary tree.
 * @tree: is A pointer to root node of the tree to measure.
 *
 * Return: The balance factor of the tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
