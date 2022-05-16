/*Given a binary tree, connect the nodes that are at same level. You'll be given an addition nextRight pointer for the same.
Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.
       10                       10 ------> NULL
      / \                       /      \
     3   5       =>     3 ------> 5 --------> NULL
    / \     \               /  \           \
   4   1   2          4 --> 1 -----> 2 -------> NULL

Example 1:

Input:
     3
   /  \
  1    2

Output:
3 1 2
1 3 2

Explanation:The connected tree is
        3 ------> NULL
     /    \
    1-----> 2 ------ NULL

Example 2:

Input:
      10
    /   \
   20   30
  /  \
 40  60

Output:
10 20 30 40 60
40 20 60 10 30

Explanation:The connected tree is
         10 ----------> NULL
       /     \
     20 ------> 30 -------> NULL
  /    \
 40 ----> 60 ----------> NULL

Your Task:
You don't have to take input. Complete the function connect() that takes root as parameter and connects the nodes at same level. 
The printing is done by the driver code. First line of the output will be level order traversal and second line will be inorder travsersal

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ Number of nodes ≤ 10^5
0 ≤ Data of a node ≤ 10^5
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left, *right, *nextRight;
};

// Sets nextRight of all nodes of a tree
void connect(struct Node* root){
    queue<Node*> q;
    q.push(root);

    // null marker to represent end of current level
    q.push(NULL); 

    // Do Level order of tree using NULL markers
    while (!q.empty()) {
        Node *p = q.front();
        q.pop();
        if (p != NULL) {

            // next element in queue represents next 
            // node at current Level 
            p->nextRight = q.front();
            if (p->left)
                q.push(p->left); 
            if (p->right)
                q.push(p->right);
        } 
       
        // if queue is not empty, push NULL to mark 
        // nodes at this level are visited
        else if (!q.empty()) 
            q.push(NULL); 
    }
}

/* UTILITY FUNCTIONS */
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newnode(int data){
    struct Node* node = (struct Node*)
                         malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = node->nextRight = NULL;
    return (node);
}

int main(){

    /* Constructed binary tree is
              10
            /   \
          8      2
        /         \
      3            90
    */
    struct Node* root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(2);
    root->left->left = newnode(3);
    root->right->right = newnode(90);

    // Populates nextRight pointer in all nodes
    connect(root);

    // Let us check the values of nextRight pointers
    printf("Following are populated nextRight pointers in \n"
     "the tree (-1 is printed if there is no nextRight) \n");
    printf("nextRight of %d is %d \n", root->data,
     root->nextRight ? root->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->left->data,
     root->left->nextRight ? root->left->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->right->data,
     root->right->nextRight ? root->right->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->left->left->data,
     root->left->left->nextRight ? root->left->left->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->right->right->data,
     root->right->right->nextRight ? root->right->right->nextRight->data : -1);
    return 0;
}
