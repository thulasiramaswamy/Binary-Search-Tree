// Size of a tree
// Traversals - Inorder, Preorder, Postorder
// Minimum value, Maximum Value of a BST
// Search an element in a BST
// Maximum depth of a BST


#include <stdio.h>
#include <stdlib.h>

// Tree Node Structure
struct Node
{
	struct Node* left;
	int dat;
	struct Node* right;
};
// Creates and returns a New Node
struct Node* newNode(int value)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->left = NULL;
	temp->dat = value;
	temp->right = NULL;
	return temp;
}
// Insertion - Iterative way
void insertNodeIter(struct Node**root, int val)
{
	struct Node *newnode = newNode(val);
	struct Node *ptr;
	if (*root == NULL)
		*root = newnode;
	else
	{
		ptr = *root;
		while (true)
		{
			if (ptr->dat > newnode->dat)
			{
				if (ptr->left == NULL)
				{
					ptr->left = newnode;					
					break;
				}
				ptr = ptr->left;
			}
			else
			{
				if (ptr->right == NULL)
				{
					ptr->right = newnode;					
					break;
				}
				ptr = ptr->right;
			}
		}
	}
}
// Insertion - Recursive Way
void insertNodeRecur(struct Node** root, int value)
{
	if (*root == NULL)
	{
		*root = newNode(value);		
		return;
	}
	else if ((*root)->dat > value)
		insertNodeRecur( (&(*root)->left), value);
	else
		insertNodeRecur((&(*root)->right), value);
}
// Calculates the size of a BST and returns
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
// returns minimum element from the tree
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
// returns maximum element from the tree
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
// Calculates maximum depth
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
int main(void)
{
	struct Node* root = NULL;
	int key;

	insertNodeRecur(&root, 10);
	insertNodeRecur(&root, 5);
	insertNodeRecur(&root, 15);
	insertNodeRecur(&root, 18);
	insertNodeRecur(&root, 25);
	insertNodeRecur(&root, 8);

	
	/*insertNodeIter(&root, 10);
	insertNodeIter(&root, 5);
	insertNodeIter(&root, 15);
	insertNodeIter(&root, 18);
	insertNodeIter(&root, 25);
	insertNodeIter(&root, 8);*/

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
