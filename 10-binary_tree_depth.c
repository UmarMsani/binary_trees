#include "binary_trees.h"

/**
 * binary_tree_depth - Will Measures the depth of a node in binary tree.
 * @tree: is A pointer to node to measure the depth
 *
 * Return: If tree is NULL, this function must return 0, else return the depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
