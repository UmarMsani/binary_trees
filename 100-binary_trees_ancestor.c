#include "binary_trees.h"

/**
 * binary_tree_ancestor - if Finds the lowest common ancestor of two nodes
 * @first: is a Pointer to the first node
 * @second: A Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *ancestor1 = first;
	const binary_tree_t *ancestor2 = second;

	while (ancestor1)
	{
		ancestor2 = second;
		while (ancestor2)
		{
			if (ancestor1 == ancestor2)
				return ((binary_tree_t *)ancestor1);
			ancestor2 = ancestor2->parent;
		}
		ancestor1 = ancestor1->parent;
	}
	return (NULL);
}
