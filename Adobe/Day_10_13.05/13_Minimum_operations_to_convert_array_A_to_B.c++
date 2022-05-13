/*Given two Arrays A[] and B[] of length N and M respectively. Find the minimum number of insertions and deletions on the array A[], required to make both the arrays identical.
Note: Array B[] is sorted and all its elements are distinct, operations can be performed at any index not necessarily at end.

Example 1:

Input:
N = 5, M = 3
A[] = {1, 2, 5, 3, 1}
B[] = {1, 3, 5}

Output: 4

Explanation:
We need to delete 2 and replace it with 3. This costs 2 steps. Further, we will have to delete the last two elements from A to obtain an identical array to B. Overall, it results in 4 steps.

Example 2:

Input:
N = 2, M = 2
A[] = {1, 4}
B[] = {1, 4}

Output : 0

Explanation:
Both the Arrays are already identical.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function minInsAndDel() which takes two integers N and M, and two arrays A of size N and B of size M respectively as input and returns the minimum insertions and deletions required.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 10^5
1 ≤ A[i], B[i] ≤ 10^5
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        map<int,int> mp;
        for(int i = 0;i < M;i++)
          mp[B[i]]++;
        vector<int> v;
        for(int i = 0;i < N;i++){
           if(mp[A[i]]){
               auto it = lower_bound(v.begin(), v.end(), A[i]);
               if(it == v.end())
                 v.push_back(A[i]);
               else
                (*it) = A[i];
           }
       }
       int ans = N+M-2*v.size();
       return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,M;
        cin>>N>>M;
        int A[N], B[M];
        for(int i = 0; i < N; i++)
            cin>>A[i];
        for(int j = 0; j < M; j++)
            cin>>B[j];
        Solution s;
        cout<<s.minInsAndDel(A, B, N, M)<<endl;
    }
}