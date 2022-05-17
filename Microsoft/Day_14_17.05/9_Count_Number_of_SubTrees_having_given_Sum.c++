/*Given a binary tree and an integer X. Your task is to complete the function countSubtreesWithSumX() that returns the count of the number of subtress having total node’s data sum equal to the value X.

Example: For the tree given below:            

              5
            /    \
        -10     3
        /    \    /  \
      9     8  -4     7

Subtree with sum 7:
             -10
            /      \
          9        8

and one node 7.

Example 1:

Input:
       5
    /    \
  -10     3
 /   \   /  \
 9   8 -4    7
X = 7

Output: 2

Explanation: Subtrees with sum 7 are [9, 8, -10] and [7] (refer the example in the problem description).

Example 2:

Input:
    1
  /  \
 2    3
X = 5

Output: 0

Explanation: No subtree has sum equal to 5.

Your Task:
You don't need to read input or print anything. 
Your task is to complete the function countSubtreesWithSumX() which takes the root node and an integer X as inputs and returns the number of subtrees of the given Binary Tree having sum exactly equal to X.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= N <= 10^3
-10^3 <= Node Value <= 10^3
*/

// C++ implementation to count subtrees that
// sum up to a given value x
#include <bits/stdc++.h>
using namespace std;

// structure of a node of binary tree
struct Node {
	int data;
	Node *left, *right;
};

// function to get a new node
Node* getNode(int data){
	// allocate space
	Node* newNode = (Node*)malloc(sizeof(Node));

	// put in the data
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// function to count subtrees that
// sum up to a given value x
int countSubtreesWithSumX(Node* root, int& count, int x){
	// if tree is empty
	if (!root)
		return 0;

	// sum of nodes in the left subtree
	int ls = countSubtreesWithSumX(root->left, count, x);

	// sum of nodes in the right subtree
	int rs = countSubtreesWithSumX(root->right, count, x);

	// sum of nodes in the subtree rooted
	// with 'root->data'
	int sum = ls + rs + root->data;

	// if true
	if (sum == x)
		count++;

	// return subtree's nodes sum
	return sum;
}

// utility function to count subtrees that
// sum up to a given value x
int countSubtreesWithSumXUtil(Node* root, int x){
	// if tree is empty
	if (!root)
		return 0;

	int count = 0;

	// sum of nodes in the left subtree
	int ls = countSubtreesWithSumX(root->left, count, x);

	// sum of nodes in the right subtree
	int rs = countSubtreesWithSumX(root->right, count, x);

	// if tree's nodes sum == x
	if ((ls + rs + root->data) == x)
		count++;

	// required count of subtrees
	return count;
}

// Driver program to test above
int main(){
	/* binary tree creation
				5
			/ \
		-10	 3
		/ \ / \
		9 8 -4 7
	*/
	Node* root = getNode(5);
	root->left = getNode(-10);
	root->right = getNode(3);
	root->left->left = getNode(9);
	root->left->right = getNode(8);
	root->right->left = getNode(-4);
	root->right->right = getNode(7);
	int x = 7;
	cout << "Count = " << countSubtreesWithSumXUtil(root, x);
	return 0;
}
