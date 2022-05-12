/*Given an array A of positive integers. Your task is to find the leaders in the array. An element of array is leader if it is greater than or equal to all the elements to its right side. 
The rightmost element is always a leader. 

Example 1:

Input:
n = 6
A[] = {16,17,4,3,5,2}

Output: 17 5 2

Explanation: The first leader is 17 as it is greater than all the elements to its right.  Similarly, the next leader is 5. 
The right most element is always a leader so it is also included.

Example 2:

Input:
n = 5
A[] = {1,2,3,4,0}

Output: 4 0

Your Task:
You don't need to read input or print anything. The task is to complete the function leader() which takes array A and n as input parameters and returns an array of leaders in order of their appearance.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 10^7
0 <= Ai <= 10^7
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        int maxm;
        vector<int> ans;
        maxm = a[n-1];
        ans.push_back(a[n-1]);
        for(int i = n-2; i >= 0; i--){
            if(a[i] >= maxm){
                ans.push_back(a[i]);
                maxm = a[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        int arr[n];
        const int mx = 1e9;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        Solution s;
        vector<int> res = s.leaders(arr, n);
        for(auto i = res.begin(); i != res.end(); i++){
            cout<<*i<<" ";
        }
        cout<<endl;
    }
    return 0;
}