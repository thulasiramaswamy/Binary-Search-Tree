// C Program to demonstrate a Binary Search Tree and selected operations on it
// Size of a BST
// Traversals - Inorder, Preorder, Postorder
// Minimum value, Maximum Value of a BST
// Search an element in a BST
// Maximum Depth of a BST
// Search a key in a BST

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node* left;
	int dat;
	struct Node* right;
};

struct Node* newNode(int value)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->left = NULL;
	temp->dat = value;
	temp->right = NULL;
	return temp;
}

void insertNode(struct Node** root, int value)
{
	if (*root == NULL)
	{
		*root = newNode(value);
		printf("\n Inserted node : %d ", value);
		return;
	}
	else if ((*root)->dat > value)
		insertNode( (&(*root)->left), value);
	else
		insertNode((&(*root)->right), value);
}
int getSize(struct Node* root)
{
	if (root == NULL) return 0;
	else
		return (getSize(root->left) + 1 + getSize(root->right));
}
// left, root, right
void InOrderTraversal(struct Node* root)
{
	if (root != NULL)
	{
		InOrderTraversal(root->left);
		printf(" %d ", root->dat);
		InOrderTraversal(root->right);
	}
}
// root, left, right
void preOrderTraversal(struct Node* root)
{	
	if (root != NULL)
	{
		printf(" %d ", root->dat);
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
	}	
}
// left, root, right
void PostOrderTraversal(struct Node* root)
{	
	if (root != NULL)
	{
		PostOrderTraversal(root->left);		
		PostOrderTraversal(root->right);
		printf(" %d ", root->dat);
	}	
}
int getMin(struct Node* root)
{
	struct Node* temp = root;
	if (root != NULL)
	{
		while (temp->left != NULL)
			temp = temp->left;
	}
	return temp->dat;
}
int getMinRecur(struct Node* root)
{
	if (root != NULL)
	{
		if (root->right != NULL)
			return (getMinRecur(root->right));
		else
			return root->dat;
	}
}
int getMax(struct Node* root)
{
	struct Node* temp = root;
	if (root != NULL)
	{
		while (temp->right != NULL)
			temp = temp->right;
	}
	return temp->dat;
}

int getMaxRecur(struct Node* root)
{
	if (root != NULL)
	{
		if (root->right != NULL)
			return (getMaxRecur(root->right));
		else
			return root->dat;
	}
}

// Search a key
int iterativeSearch(struct Node* root, int key)
{
	while (root != NULL)
	{
		if (key > root->dat)
			root = root->right;
		else if (key < root->dat)
			root = root->left;
		else
			return 1;
	}
	return 0;
}

// Depth of a tree is number of edges from the Root Node
int maxDepth(struct Node* root)
{
	int leftDepth  = 0;
	int rightDepth = 0;
	if (root == NULL) return 0;
	else
	{
		leftDepth = maxDepth(root->left);
		rightDepth = maxDepth(root->right);
		if (leftDepth > rightDepth) return (leftDepth + 1);
		else return (rightDepth + 1);
	}
}

// Driver Function
int main(void)
{
	struct Node* root = NULL;
	int key;
	insertNode(&root, 10);
	insertNode(&root, 5);
	insertNode(&root, 15);
	insertNode(&root, 18);
	insertNode(&root, 25);
	insertNode(&root, 8);

	printf("\n\nSize of the tree : %d\n\n", getSize(root));

	printf("\nPreOrderTraversal	: ");
	preOrderTraversal(root);

	printf("\nInOrderTraversal	: ");
	InOrderTraversal(root);

	printf("\nPostOrderTraversal	: ");
	PostOrderTraversal(root);
	printf("\n\n");
	printf("\n Minimum element in the tree : %d ", getMin(root));
	printf("\n Maximum element in the tree : %d ", getMax(root));
	
	key = 1;

	if (iterativeSearch(root, key))
		printf("\n %d Found", key);
	else
		printf("\n %d Not Found", key);

	printf("\n\nMaximum Depth 	: %d ", maxDepth(root));
	printf("\n\n");
	return 0;
}
