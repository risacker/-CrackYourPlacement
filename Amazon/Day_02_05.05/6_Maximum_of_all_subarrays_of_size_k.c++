/*Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

Example 1:

Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6

Output: 
3 3 4 5 5 5 6 

Explanation: 
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6

Example 2:

Input:
N = 10, K = 4
arr[] = 8 5 10 7 9 4 15 12 90 13

Output: 
10 10 10 15 15 90 90

Explanation: 
1st contiguous subarray = {8 5 10 7}, Max = 10
2nd contiguous subarray = {5 10 7 9}, Max = 10
3rd contiguous subarray = {10 7 9 4}, Max = 10
4th contiguous subarray = {7 9 4 15}, Max = 15
5th contiguous subarray = {9 4 15 12}, 
Max = 15
6th contiguous subarray = {4 15 12 90},
Max = 90
7th contiguous subarray = {15 12 90 13}, 
Max = 90

Your Task:  
You dont need to read input or print anything. Complete the function max_of_subarrays() which takes the array, N and K as input parameters and returns a list of integers denoting the maximum of every contiguous subarray of size K.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(k)

Constraints:
1 ≤ N ≤ 10^7
1 ≤ K ≤ N
0 ≤ arr[i] ≤ 10^7
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k){
        // your code here
       multiset<int>s;//multi set allows duplication 
       vector<int>ans;
       for(int i = 0;i < k;i++){
           s.insert(arr[i]);
       }
       ans.push_back(*(s.rbegin()));
       for(int i = k;i < n;i++){
           s.insert(arr[i]);
           int x = arr[i-k];
           auto it = s.find(x);
           s.erase(it);//delete first occurence only not all
           ans.push_back(*(s.rbegin()));
       }
       return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        Solution s;
        vector<int> res = s.max_of_subarrays(arr, n, k);
        for(int i = 0; i < res.size(); i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}