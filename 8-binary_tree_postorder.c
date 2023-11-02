#include "binary_trees.h"

/**
 * binary_tree_postorder - it Traverses binary tree using post-order traversal
 * @func: is A pointer to function to call for each node
 * @tree: Is A pointer to root node of a tree to traverse.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
