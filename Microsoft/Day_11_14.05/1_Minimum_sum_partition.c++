/*Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference

Example 1:

Input: N = 4, arr[] = {1, 6, 11, 5} 

Output: 1

Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11   

Example 2:

Input: N = 2, arr[] = {1, 4}

Output: 3

Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {4}, sum of Subset2 = 4

Your Task:  
You don't need to read input or print anything. Complete the function minDifference() which takes N and array arr as input parameters and returns the integer value

Expected Time Complexity: O(N*|sum of array elements|)
Expected Auxiliary Space: O(N*|sum of array elements|)

Constraints:
1 ≤ N*|sum of array elements| ≤ 10^6*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    vector<int>w(arr,arr+n),T[n+1];
        int sum = accumulate(w.begin(),w.end(),0);
        int i,j,k,l;
        for(i = 0;i < n+1;++i){
            for(j = 0;j < sum+1;++j){
                T[i].push_back(-1);
            }
        }
        for(i = 0;i < n+1;++i){
            for(j = 0;j < sum+1;++j){
                if(j == 0){
                    T[i][j] = 1;
                }
                else if(i == 0){
                    T[i][j] = 0;
                }
                else if(w[i-1] <= j){
                    T[i][j] = (T[i-1][j] || T[i-1][j-w[i-1]]);
                }
                else{
                    T[i][j]  = T[i-1][j];
                }
            }
        }
        vector<int> pos;
        for(i = 0;i < sum+1;++i){
            if(T[n][i]==1){
              pos.push_back(i);
            }
        }
        int p = pos.size();
        if(p%2 ==0){
            k = p/2;
        }
        else{
            k = (p+1)/2;
        }
        int mid = pos[k-1];
        int rem = sum - mid;
        int val = rem - mid;
        return val;
	} 
};

int main(){
    int t;
    cin>>t;
        for(int i = 0; i < t; i++){
            int n;
            cin>>n;
            int arr[n];   
            for(int i = 0; i < n; i++){
                cin>>arr[i];
            }
            Solution s;
            cout<<s.minDifference(arr, n)<<endl;
    }
    return 0;
}