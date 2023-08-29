#include "binary_trees.h"

/**
 * binary_tree_is_perfect - find if the binary tree is perfect
 * @tree: the root node
 *
 * Return: 1 if perfect else 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height = 0;
	int nodes = 0;
	int power = 0;

	if (tree == NULL)
		return (0);
	height = (int)binary_tree_height(tree);
	nodes = (int)binary_tree_size(tree);

	power = _power(2, height + 1);
	return (power - 1 == nodes);
}
/**
 * _power - a function that returns the power of two numbers
 * @x: the first argument
 * @y: the second argument
 *
 * Return: the power of two numbers
 */

int _power(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	else
		return (x * (_power(x, y - 1)));
}

/**
 * binary_tree_size - a function that returns the size of the binary tree
 * @tree: the root node
 *
 * Return: the size of the binary tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_height - a function that returns the height of a binary tree
 * @tree: the root node
 *
 * Return: the height of the binary tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right_height = 0;
	size_t left_height = 0;

	if (tree == NULL)
		return (0);
	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);
	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);
	if (right_height > left_height)
		return (right_height);
	return (left_height);
}
