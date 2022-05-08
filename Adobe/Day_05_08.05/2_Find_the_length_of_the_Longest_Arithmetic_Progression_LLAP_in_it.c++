/*Given an array called A[] of sorted integers having no duplicates, find the length of the Longest Arithmetic Progression (LLAP) in it.

Example 1:

Input:
N = 6
set[] = {1, 7, 10, 13, 14, 19}

Output: 4

Explanation: The longest arithmetic progression is {1, 7, 13, 19}.

Example 2:

Input:
N = 5
A[] = {2, 4, 6, 8, 10}

Output: 5

Explanation: The whole set is in AP.

Your Task:
You don't need to read input or print anything. Your task is to complete the function lenghtOfLongestAP() which takes the array of integers called set[] and n as input parameters and returns the length of LLAP.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N2)

Constraints:
1 ≤ N ≤ 1000
1 ≤ set[i] ≤ 104
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
        vector<vector<int>> dp(1001 , vector<int>(10005 , 0));
        int mx = 0;
        for (int i = 1 ; i < n ; i++){
            for (int j = 0 ; j < i ; j++){
                dp[i][A[i]-A[j]] = max(dp[i][A[i]-A[j]] , 1 + dp[j][A[i]-A[j]]);
                mx = max(dp[i][A[i]-A[j]], mx);
            }
        }
        return mx+1;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0; i < N; i++){
            cin>>A[i];
        }
        Solution s;
        cout<<s.lengthOfLongestAP(A, N)<<endl;
    }
}