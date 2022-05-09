/*Given two numbers n and x, find out the total number of ways n can be expressed as sum of xth power of unique natural numbers.
As total number of ways can be very large ,so return the number of ways modulo 10^9 + 7. 

Example 1:

Input: n = 10, x = 2

Output: 1 

Explanation: 10 = 12 + 32, Hence total 1 possibility. 

Example 2:

Input: n = 100, x = 2

Output: 3

Explanation: 100 = 102 
62 + 82 and 12 + 32 + 42 + 52 + 72 
Hence total 3 possibilities. 

Your Task:  
You dont need to read input or print anything. Complete the function numOfWays() which takes n and x as input parameter and returns the total number of ways n can be expressed as sum of xth power of unique natural numbers.

Expected Time Complexity: O(n2logn)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 103
1 <= x <= 5
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int numOfWays(int n, int x){
        // code here
        vector<long long int> v(n,0);
        for (int i = 0; i < n; ++i){
            v[i] = (long long int)pow(i+1,x);
        }
        int sum=n;
        long long int dp[n+1][sum+1];
        for(int i = 0;i <= n;i++)
            dp[i][0] = 1;
        for(int j = 1;j <= sum;j++)
            dp[0][j] = 0;
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= sum; ++j){
                dp[i][j] = dp[i-1][j]%(1000000007);
                if(j >= v[i-1])
                   dp[i][j] = (dp[i][j]+dp[i-1][j-v[i-1]])%(1000000007);
            }
        }
        return dp[n][sum]%(1000000007);
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        Solution s;
        cout<<s.numOfWays(N, K)<<endl;
    }
}