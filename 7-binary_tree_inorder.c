#include "binary_trees.h"

/**
 * binary_tree_inorder - it Goes through binary tree using in-order traversal
 * @func: is A pointer to function to call for each node.
 * @tree: Is A pointer to root node of a tree to traverse.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
