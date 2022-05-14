/*Given a square matrix[][] of size N x N. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space.

Example 1:

Input:
N = 3
matrix[][] = [[1 2 3], [4 5 6], [7 8 9]]

Output:
3 6 9 
2 5 8 
1 4 7

Your Task:
You only need to implement the given function rotate(). Do not read input, instead use the arguments given in the function. 

Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 50
1 <= matrix[][] <= 100
*/

#include <bits/stdc++.h>
#define N 4
using namespace std;

void displayMatrix(int mat[N][N]);

// An Inplace function to
// rotate a N x N matrix
// by 90 degrees in
// anti-clockwise direction
void rotateMatrix(int mat[][N])
{ // REVERSE every row
    for (int i = 0; i < N; i++)
        reverse(mat[i], mat[i] + N);

    // Performing Transpose
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++)
            swap(mat[i][j], mat[j][i]);
    }
}

// Function to print the matrix
void displayMatrix(int mat[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%2d ", mat[i][j]);

        printf("\n");
    }
    printf("\n");
}

int main(){
    int mat[N][N] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
    rotateMatrix(mat);
    // Print rotated matrix
    displayMatrix(mat);
    return 0;
}