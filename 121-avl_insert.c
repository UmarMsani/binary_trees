#include "binary_trees.h"

/**
 * avl_insert - To Inserts a value in an AVL Tree
 * @tree: is A double pointer to root node of the AVL tree.
 * @value: is The value to insert.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		if (*tree == NULL)
			return (NULL);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert(&((*tree)->left), value);
		(*tree)->left->parent = *tree;
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert(&((*tree)->right), value);
		(*tree)->right->parent = *tree;
	}
	else
	{
		return (*tree);
	}

	int balance = binary_tree_balance(*tree);

	/* Left heavy */
	if (balance > 1 && value < (*tree)->left->n)
	{
		return (binary_tree_rotate_right(*tree));
	}

	/* Right heavy */
	if (balance < -1 && value > (*tree)->right->n)
	{
		return (binary_tree_rotate_left(*tree));
	}

	/* Left Right Case */
	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (binary_tree_rotate_right(*tree));
	}

	/* Right Left Case */
	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (binary_tree_rotate_left(*tree));
	}

	return (*tree);
}
