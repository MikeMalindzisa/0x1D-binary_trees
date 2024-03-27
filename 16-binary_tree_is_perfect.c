#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the binary tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	/* Calculate the height of the left subtree */
	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);

	/* Calculate the height of the right subtree */
	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	/* Return the maximum height of the left and right subtrees */
	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_height, right_height;

	/* If tree is NULL, it cannot be perfect */
	if (tree == NULL)
		return (0);

	/* Check if the tree is full */
	if (!binary_tree_is_full(tree))
		return (0);

	/* Get the height of the left and right subtrees */
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	/**
	 * If the height of the left
	 * and right subtrees are equal,
	 * the tree is perfect
	 */
	return (left_height == right_height);
}

