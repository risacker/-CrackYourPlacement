/*Serialization is to store a tree in an array so that it can be later restored and Deserialization is reading tree back from the array. 
Now your task is to complete the function serialize which stores the tree into an array A[ ] and deSerialize which deserializes the array to the tree and returns it.
Note: The structure of the tree must be maintained. Multiple nodes can have the same data.

Example 1:

Input:
      1
    /   \
   2     3

Output: 2 1 3

Example 2:

Input:
         10
       /    \
      20    30
    /   \
   40  60

Output: 40 20 60 10 30

Your Task:
The task is to complete two function serialize which takes the root node of the tree as input and stores the tree into an array and deSerialize which deserializes the array to the original tree and returns the root of it.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 1000
1 <= Data of a node <= 1000*/

// A C program to demonstrate serialization and deserialization of
// Binary Tree
#include <stdio.h>
#define MARKER -1

/* A binary tree Node has key, pointer to left and right children */
struct Node
{
	int key;
	struct Node* left, *right;
};

/* Helper function that allocates a new Node with the
given key and NULL left and right pointers. */
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}

// This function stores a tree in a file pointed by fp
void serialize(Node *root, FILE *fp)
{
	// If current node is NULL, store marker
	if (root == NULL)
	{
		fprintf(fp, "%d ", MARKER);
		return;
	}

	// Else, store current node and recur for its children
	fprintf(fp, "%d ", root->key);
	serialize(root->left, fp);
	serialize(root->right, fp);
}

// This function constructs a tree from a file pointed by 'fp'
void deSerialize(Node *&root, FILE *fp)
{
	// Read next item from file. If there are no more items or next
	// item is marker, then return
	int val;
	if ( !fscanf(fp, "%d ", &val) || val == MARKER)
	return;

	// Else create node with this item and recur for children
	root = newNode(val);
	deSerialize(root->left, fp);
	deSerialize(root->right, fp);
}

// A simple inorder traversal used for testing the constructed tree
void inorder(Node *root)
{
	if (root)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

/* Driver program to test above functions*/
int main()
{
	// Let us construct a tree shown in the above figure
	struct Node *root	 = newNode(20);
	root->left			 = newNode(8);
	root->right			 = newNode(22);
	root->left->left		 = newNode(4);
	root->left->right	 = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);

	// Let us open a file and serialize the tree into the file
	FILE *fp = fopen("tree.txt", "w");
	if (fp == NULL)
	{
		puts("Could not open file");
		return 0;
	}
	serialize(root, fp);
	fclose(fp);

	// Let us deserialize the stored tree into root1
	Node *root1 = NULL;
	fp = fopen("tree.txt", "r");
	deSerialize(root1, fp);

	printf("Inorder Traversal of the tree constructed from file:\n");
	inorder(root1);

	return 0;
}
