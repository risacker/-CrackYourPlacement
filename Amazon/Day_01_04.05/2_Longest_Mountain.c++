/*You may recall that an array arr is a mountain array if and only if:

    arr.length >= 3
    There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
      arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
      arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

Example 1:

Input: arr = [2,1,4,7,3,2,5]

Output: 5

Explanation: The largest mountain is [1,4,7,3,2] which has length 5.

Example 2:

Input: arr = [2,2,2]

Output: 0

Explanation: There is no mountain.
 
Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 104*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int N = arr.size();
        int ans = 0,base = 0;
        while(base < N) {
            int end = base;
            // if base is a left-boundary
            if(end + 1 < N && arr[end] < arr[end + 1]) {
                // set end to the peak of this potential mountain
                while(end + 1 < N && arr[end] < arr[end + 1]) 
                    end++;
                // if end is really a peak..
                if(end + 1 < N && arr[end] > arr[end + 1]) {
                    // set end to the right-boundary of mountain
                    while (end + 1 < N && arr[end] > arr[end + 1]) 
                        end++;
                    // record candidate answer
                    ans = max(ans, end - base + 1);
                }
            }
            base = max(end, base + 1);
        }
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin>>arr[i];
        }
        Solution s;
        vector<int> res = s.longestMountain(arr);
        for(int i = 0; i < res.size(); i++){
            cout<<res[i]<<endl;
        }
    }
}