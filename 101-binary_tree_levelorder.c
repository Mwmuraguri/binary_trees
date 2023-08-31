#include "binary_trees.h"

/**
 * binary_tree_height_aux -  a tree
 * @tree: Pointer to
 * Return: Trees
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is empty, return 0.
 * 2. If the tree is not empty,
 * then height = 1 + max of left height and right heights.
 *
 * 3. Use the recursive helper function to get the
 * height of left and right subtrees of the current node recursively.
 *
 * 4. Get the max of left height and right height and
 * add 1 to it for the current node.
 *
 * 5. Return the height.
 *
 * Time Complexity: O(n)
 */
size_t binary_tree_height_aux(const binary_tree_t *tree)
{
	size_t hleft = 0, hright = 0;

	if (!tree)
		return (0);
	if (tree->left)
		hleft = 1 + binary_tree_height_aux(tree->left);
	if (tree->right)
		hright = 1 + binary_tree_height_aux(tree->right);

	if (hleft > hright)
		return (hleft);
	return (hright);
}

/**
 * print_level_order - print each
 * @tree: pointer to thse
 * @level: level of the tree
 * @func: pointer to a  node
 * Return: void
 *
 */

void print_level_order(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_level_order(tree->left, level - 1, func);
		print_level_order(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - function that goes through a
 * binary tree
 * @tree: pointer
 * @func: pointer to a function to call for each node
 * Return: void
 *
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = 0;
	int len = 1;

	if (!tree || !func)
		return;

	height = binary_tree_height_aux(tree) + 1;

	while (len <= height)
	{
		print_level_order(tree, len, func);
		len++;
	}
}
