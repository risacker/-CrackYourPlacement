/*Given a matrix of size r*c. Traverse the matrix in spiral form.

Example 1:

Input:
r = 4, c = 4
matrix[][] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15,16}}

Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

Explanation:

Example 2:

Input:
r = 3, c = 4  
matrix[][] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}

Output: 
1 2 3 4 8 12 11 10 9 5 6 7

Explanation:
Applying same technique as shown above, output for the 2nd testcase will be 1 2 3 4 8 12 11 10 9 5 6 7.

Your Task:
You dont need to read input or print anything. Complete the function spirallyTraverse() that takes matrix, r and c as input parameters and returns a list of integers denoting the spiral traversal of matrix. 

Expected Time Complexity: O(r*c)
Expected Auxiliary Space: O(r*c), for returning the answer only.

Constraints:
1 <= r, c <= 100
0 <= matrixi <= 100
*/

#include <iostream>
using namespace std;
#define R 4
#define C 4

// Function for printing matrix in spiral
// form i, j: Start index of matrix, row
// and column respectively m, n: End index
// of matrix row and column respectively
void print(int arr[R][C], int i, int j, int m, int n){
    // If i or j lies outside the matrix
    if (i >= m or j >= n)
        return;

    // Print First Row
    for (int p = j; p < n; p++)
        cout << arr[i][p] << " ";

    // Print Last Column
    for (int p = i + 1; p < m; p++)
        cout << arr[p][n - 1] << " ";
    if ((m - 1) != i)
        for (int p = n - 2; p >= j; p--)
            cout << arr[m - 1][p] << " ";

    // Print First Column,  if Last and
    // First Column are not same
    if ((n - 1) != j)
        for (int p = m - 2; p > i; p--)
            cout << arr[p][j] << " ";
    print(arr, i + 1, j + 1, m - 1, n - 1);
}

int main(){
    int a[R][C] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
    print(a, 0, 0, R, C);
    return 0;
}