#include "binary_trees.h"

/**
 * binary_tree_balance - it will Measures the balance factor of binary tree
 * @tree: A pointer to root node of tree to measure the balance factor
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - it will Measures the height of binary tree.
 * @tree: is A pointer to root node of the tree to measure the height.
 *
 * Return: If tree is NULL, this function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t x = 0, y = 0;

		x = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		y = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((x > y) ? x : y);
	}
	return (0);
}
