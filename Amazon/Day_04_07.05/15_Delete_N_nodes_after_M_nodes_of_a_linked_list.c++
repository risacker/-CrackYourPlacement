/*Given a linked list, delete N nodes after skipping M nodes of a linked list until the last of the linked list.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of elements in the linked list and next M and N respectively space separated. 
The last line contains the elements of the linked list.

Output:
Function should not print any output to stdin/console.

User Task:
The task is to complete the function linkdelete() which should modify the linked list as required.

Example:

Input:
2
8
2 1
9 1 3 5 9 4 10 1
6
6 1
1 2 3 4 5 6

Output: 
9 1 5 9 10 1
1 2 3 4 5 6

Explanation:
Testcase 1: Deleting one node after skipping the M nodes each time, we have list as 9-> 1-> 5-> 9-> 10-> 1.
*/

// C++ program to delete N nodes
// after M nodes of a linked list
#include <bits/stdc++.h>
using namespace std;

// A linked list node
class Node
{
	public:
	int data;
	Node *next;
};

/* Function to insert a node at the beginning */
void push(Node ** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print linked list */
void printList(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

// Function to skip M nodes and then
// delete N nodes of the linked list.
void skipMdeleteN(Node *head, int M, int N)
{
	Node *curr = head, *t;
	int count;

	// The main loop that traverses
	// through the whole list
	while (curr)
	{
		// Skip M nodes
		for (count = 1; count < M &&
				curr!= NULL; count++)
			curr = curr->next;

		// If we reached end of list, then return
		if (curr == NULL)
			return;

		// Start from next node and delete N nodes
		t = curr->next;
		for (count = 1; count<=N && t!= NULL; count++)
		{
			Node *temp = t;
			t = t->next;
			free(temp);
		}
		
		// Link the previous list with remaining nodes
		curr->next = t;

		// Set current pointer for next iteration
		curr = t;
	}
}

// Driver code
int main()
{
	/* Create following linked list
	1->2->3->4->5->6->7->8->9->10 */
	Node* head = NULL;
	int M=2, N=3;
	push(&head, 10);
	push(&head, 9);
	push(&head, 8);
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	cout << "M = " << M<< " N = " << N << "\nGiven Linked list is :\n";
	printList(head);

	skipMdeleteN(head, M, N);

	cout<<"\nLinked list after deletion is :\n";
	printList(head);

	return 0;
}

// This code is contributed by rathbhupendra
