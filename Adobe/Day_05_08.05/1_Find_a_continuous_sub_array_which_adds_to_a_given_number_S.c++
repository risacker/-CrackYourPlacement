/*Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.
In case of multiple subarrays, return the subarray which comes first on moving from left to right.

Example 1:

Input:
N = 5, S = 12
A[] = {1,2,3,7,5}

Output: 2 4

Explanation: The sum of elements from 2nd position to 4th position is 12. 

Example 2:

Input:
N = 10, S = 15
A[] = {1,2,3,4,5,6,7,8,9,10}

Output: 1 5

Explanation: The sum of elements from 1st position to 5th positionis 15. 

Your Task:
You don't need to read input or print anything. The task is to complete the function subarraySum() which takes arr, N and S as input parameters and returns a list containing the starting and ending positions of the first such occurring subarray from the left where sum equals to S. 
The two indexes in the list should be according to 1-based indexing. If no such subarray is found, return an array consisting only one element that is -1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
1 <= Ai <= 109*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s){
        // Your code here
        vector<int> ans;
        long long curr_s = 0;
        long long st = 0;
        long long i = 0;
        while(curr_s != s && st < n){
            curr_s += arr[i];
            i++;
            while(curr_s > s){
                curr_s -= arr[st];
                st++;
            }
        }
        if(curr_s == s){
            ans.push_back(st+1);
            ans.push_back(i);
            return ans;
        }
        ans.push_back(-1);
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        long long str;
        cin>>n>>str;
        int arr[n];
        const int mx = 1e9;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        Solution s;
        vector<int> res = s.subarraySum(arr, n, str);
        for(int i = 0; i < res.size(); i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}