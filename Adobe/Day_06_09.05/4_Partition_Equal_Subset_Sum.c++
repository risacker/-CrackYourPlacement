/*Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}

Output: YES

Explaination: 
The two parts are {1, 5, 5} and {11}.

Example 2:

Input: N = 3
arr = {1, 3, 5}

Output: NO

Explaination: This array can never be partitioned into two such parts.

Your Task:
You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.

Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)

Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000
*/

#include<bits/stdc++.h>
using namespace std;

const int n = 1e2, m = 1e5;
bool dp[n][m + 1];
class Solution{
public:
    int equalPartition(int N, int arr[]){
        // code here
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
        if (sum & 1) 
          return false;
        memset(dp, false, sizeof(dp));
        dp[0][0] = dp[0][arr[0]] = true;
        for(int i = 1; i < N; i++) {
            dp[i][0] = true;
            for (int j = 0; j <= sum; j++) {
                dp[i][j] |= dp[i - 1][j];
                dp[i][j + arr[i]] |= dp[i - 1][j];
            }
        }
        return dp[N - 1][sum >> 1];
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        const int mx = 1e9;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        Solution s;
        if(s.equalPartition(n, arr))
           cout<<"YES"<<endl;
        else
           cout<<"NO"<<endl;
    }
    return 0;
}