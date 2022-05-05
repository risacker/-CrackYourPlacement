/*Given an incomplete Sudoku configuration in terms of a 9x9  2-D square matrix(mat[][]) the task to check if the current configuration is valid or not where a 0 represents an empty block.
Note: Current valid configuration does not ensure validity of the final solved sudoku. 
Refer to this : https://en.wikipedia.org/wiki/Sudoku

Example 1:

Input: mat[][] = [
[3, 0, 6, 5, 0, 8, 4, 0, 0]
[5, 2, 0, 0, 0, 0, 0, 0, 0]
[0, 8, 7, 0, 0, 0, 0, 3, 1]
[0, 0, 3, 0, 1, 0, 0, 8, 0]
[9, 0, 0, 8, 6, 3, 0, 0, 5]
[0, 5, 0, 0, 9, 0, 6, 0, 0]
[1, 3, 0, 0, 0, 0, 2, 5, 0]
[0, 0, 0, 0, 0, 0, 0, 7, 4]
[0, 0, 5, 2, 0, 6, 3, 0, 0]
]

Output: 1

Explaination: It is possible to have a proper sudoku.

Your Task:
You do not need to read input or print anything. Your task is to complete the function isValid() which takes mat[][] as input parameter and returns 1 if any solution is possible. 
Otherwise, returns 0.

Expected Time Complexity: O(N^2)
Expected Auxiliary Space: O(1)

Constraints:
0 ≤ mat[i][j] ≤ 9*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        int maxi = 15;
        int n=9;
        
        //setting the matrix
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                int temp = mat[i][j]%maxi;
                if(temp){
                  mat[i][temp-1] += maxi;
                  if(mat[i][temp-1]/maxi > 1) 
                    return false;
                    
                }
            }
        }
        
        //resetting the matrix
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                mat[i][j] = mat[i][j]%maxi;
            }
        }
        
        //setting the matrix
        for(int j = 0;j < n;j++){
            for(int i = 0;i < n;i++){
                int temp = mat[i][j]%maxi;
                if(temp){
                  mat[temp-1][j] += maxi;
                  if(mat[temp-1][j]/maxi > 1)
                    return false;
                    
                }
            }
        }
        
        //Resetting the matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = mat[i][j]%maxi;
            }
        }
        
        //setting the matrix
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
               int i1 = i/3;
               int j1= j/3;
               int in;
               if(i1 == 0)  
                 in = j1;
               if(i1 == 1)  
                 in = 3+j1;
               if(i1 == 2)  
                 in = 6+j1;
               int temp = mat[i][j]%maxi;
               if(temp){
                mat[in][temp-1] += maxi;
                if(mat[in][temp-1]/maxi > 1) 
                    return false;
                   
               }
            }
        }
        return true;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0; i < 81; i++){
            cin>>mat[i/9][i%9];
        }
        Solution ob;
        cout<<ob.isValid(mat)<<endl;
    }
}
