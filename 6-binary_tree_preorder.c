#include "binary_trees.h"

/**
 * binary_tree_preorder - it Goes through binary tree using pre-order traversal
 * @func: Is A pointer to a function to call for each node.
 * @tree: is A pointer to the root node of a tree to traverse.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
