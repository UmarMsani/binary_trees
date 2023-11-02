#include "binary_trees.h"

static avl_t *create_node(avl_t *parent, int value);
static avl_t *insert_recursive(avl_t **tree, int value);
static avl_t *balance_tree(avl_t **tree, int value);

/**
 * create_node - Creates a new node with the given value and parent.
 * @parent: The parent node of the new node.
 * @value: The value to be set in the new node.
 *
 * Return: A pointer to the new node.
 */
static avl_t *create_node(avl_t *parent, int value)
{
	avl_t *new_node = malloc(sizeof(avl_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * insert_recursive - Inserts a value recursively into an AVL Tree.
 * @tree: A pointer to a pointer to the root node of the AVL tree.
 * @value: The value to insert.
 *
 * Return: A pointer to the new node.
 */
static avl_t *insert_recursive(avl_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = create_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		(*tree)->left = insert_recursive(&((*tree)->left), value);
		(*tree)->left->parent = *tree;
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = insert_recursive(&((*tree)->right), value);
		(*tree)->right->parent = *tree;
	}

	return (*tree);
}

/**
 * balance_tree - Balances the tree after insertion.
 * @tree: A pointer to a pointer to the root node of the AVL tree.
 * @value: The value that was inserted.
 *
 * Return: A pointer to the new root node of the balanced tree.
 */
static avl_t *balance_tree(avl_t **tree, int value)
{
	int balance = binary_tree_balance(*tree);

	if (balance > 1 && value < (*tree)->left->n)
		return (binary_tree_rotate_right(*tree));

	if (balance < -1 && value > (*tree)->right->n)
		return (binary_tree_rotate_left(*tree));

	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (binary_tree_rotate_right(*tree));
	}

	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (binary_tree_rotate_left(*tree));
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value in an AVL Tree.
 * @tree: A pointer to a pointer to the root node of the AVL tree.
 * @value: The value to insert.
 *
 * Return: A pointer to the new root node of the balanced tree.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	insert_recursive(tree, value);

	return (balance_tree(tree, value));
}
