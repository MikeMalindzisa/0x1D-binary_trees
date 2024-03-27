#include "binary_trees.h"

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

	/*
	 * If the height of the left
	 * and right subtrees are equal,
	 * the tree is perfect
	 */
	return (left_height == right_height);
}

