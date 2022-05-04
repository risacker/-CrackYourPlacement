/*Given an array p[] of length n used to denote the dimensions of a series of matrices such that dimension of i'th matrix is p[i] * p[i+1]. 
There are a total of n-1 matrices. Find the most efficient way to multiply these matrices together. 
The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications such that you need to perform minimum number of multiplications. 
There are many options to multiply a chain of matrices because matrix multiplication is associative i.e. no matter how one parenthesize the product, the result will be the same.

Example 1:

Input: 
n = 5
p[] = {1, 2, 3, 4, 5}

Output: (((AB)C)D)

Explaination: The total number of multiplications are (1*2*3) + (1*3*4) + (1*4*5) = 6 + 12 + 20 = 38.
 
Example 2:

Input: 
n = 3
p = {3, 3, 3}

Output: (AB)

Explaination: The total number of multiplications are (3*3*3) = 27.
 
Your Task:
You do not need to read input or print anything. Your task is to complete the function matrixChainOrder() which takes n and p[] as input parameters and returns the string with the proper order of parenthesis for n-1 matrices. Use uppercase alphabets to denote each matrix.

Expected Time Complexity: O(n3)
Expected Auxiliary Space: O(n2)

Constraints:
2 ≤ n ≤ 26 
1 ≤ p[i] ≤ 500 */

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string matrixChainOrder(int p[], int n){
        // code here
        map<pair<int,int>, string> mp;
        int dp[n-1][n-1];
        for(int i = 0, j = 0; j < n-1; ++j){
            int r = i,c = j, len = n-1-j;
            while(len--){
                if(j==0){
                    dp[r][c] =0;
                    string str = "";
                    char ch = 'A'+ (n-1-len-1);
                    str = str + ch;
                    mp[make_pair(r,c)] = str;
                    r++; c++;
                }
                else if(j == 1){
                    dp[r][c] = p[r] * p[c] * p[c+1];
                    mp[make_pair(r,c)] = '('+ mp[make_pair(r,c-1)] + mp[make_pair(r+1,c)]+ ')';
                    r++, c++;
                }
                else{
                    int right, down;
                    dp[r][c] = INT_MAX;
                    for(right = r, down = r+1; right <= c && down <= c; right++, down++){
                        int operations = dp[r][right] + dp[down][c] + p[r] * p[down] * p[c+1];
                        if(dp[r][c] > operations){
                           dp[r][c] = operations;
                           mp[make_pair(r,c)] = '(' + mp[make_pair(r,right)] + mp[make_pair(down,c)]+')';
                        }
                    }
                    r++, c++;
                }
            }
        } 
     return mp[make_pair(0,n-2)];
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0; i < n; i++){
            cin>>p[i];
        }
        Solution s;
        cout<<s.matrixChainOrder(p,n)<<endl;
        }
}