#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the binary tree. If tree is NULL, return 0.
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

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise. If tree is NULL, return 0.
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
