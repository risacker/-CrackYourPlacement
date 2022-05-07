/*Given a binary tree and a node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. 
It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.

Example 1:

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8

Output: 7

Explanation: If leaf with the value 8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.

Example 2:

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10

Output: 5

Your Task:  
You don't need to read input or print anything. Complete the function minTime() which takes the root of the tree and target as input parameters and returns the minimum time required to burn the complete binary tree if the target is set on fire at the 0th second.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)

Constraints:
1 ≤ N ≤ 104
*/

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(){
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val){
    Node* temp = new Node;
    temp->data = val;
    return temp;
}

struct Info {
    int lDepth;
    int rDepth;
    bool contains;
    int time;
    Info(){
        lDepth = rDepth = 0;
        contains = false;
        time = -1;
    }
};

Info calcTime(Node* node, Info& info, int target, int& res){
    if (node == NULL) {
        return info;
    }
    if (node->left == NULL && node->right == NULL) {
        if (node->data == target) {
            info.contains = true;
            info.time = 0;
        }
        return info;
    }

    Info leftInfo;
    calcTime(node->left, leftInfo, target, res);
    Info rightInfo;
    calcTime(node->right, rightInfo, target, res);
    info.time = (node->left && leftInfo.contains) ? (leftInfo.time + 1) : -1;
    if (info.time == -1)
        info.time = (node->right && rightInfo.contains) ? (rightInfo.time + 1) : -1;
    info.contains = ((node->left && leftInfo.contains) || (node->right && rightInfo.contains));
    info.lDepth = !(node->left) ? 0 : (1 + max(leftInfo.lDepth, leftInfo.rDepth));
    info.rDepth = !(node->right) ? 0 : (1 + max(rightInfo.lDepth, rightInfo.rDepth));
    if (info.contains) {
        if (node->left && leftInfo.contains) {
            res = max(res, info.time + info.rDepth);
        }
        if (node->right && rightInfo.contains) {
            res = max(res, info.time + info.lDepth);
        }
    }
}

int minTime(Node* root, int target){
    int res = 0;
    Info info;
    calcTime(root, info, target, res);
    return res;
}


int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->left->left->left = newNode(8);
    root->left->right->left = newNode(9);
    root->left->right->right = newNode(10);
    root->left->right->left->left = newNode(11);
    int target = 11;
    cout << minTime(root, target);
    return 0;
}