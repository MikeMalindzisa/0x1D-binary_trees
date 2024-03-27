#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to the uncle node, or NULL if no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* If node is NULL or has no parent or grandparent, return NULL */
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	/* Return the sibling of the parent node */
	return (binary_tree_sibling(node->parent));
}

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node to find the sibling
 *
 * Return: Pointer to the sibling node, or NULL if no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* If node or parent is NULL, or node has no sibling, return NULL */
	if (node == NULL || node->parent == NULL ||
		(node->parent->left == NULL || node->parent->right == NULL))
		return (NULL);

	/* Return the sibling node */
	return (node->parent->left == node ?
			node->parent->right : node->parent->left);
}

