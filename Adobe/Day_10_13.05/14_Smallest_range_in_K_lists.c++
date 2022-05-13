/*Given K sorted lists of integers, KSortedArray[] of size N each. The task is to find the smallest range that includes at least one element from each of the K lists. If more than one such range's are found, return the first such range found.

Example 1:

Input:
N = 5, K = 3
KSortedArray[][] = {{1 3 5 7 9}, {0 2 4 6 8}, {2 3 5 7 11}}

Output: 1 2

Explanation: K = 3
A:[1 3 5 7 9]
B:[0 2 4 6 8]
C:[2 3 5 7 11]
Smallest range is formed by number 1 present in first list and 2 is present in both 2nd and 3rd list.

Example 2:

Input:
N = 4, K = 3
KSortedArray[][] = {{1 2 3 4}, {5 6 7 8}, {9 10 11 12}}

Output: 4 9

Your Task :
Complete the function findSmallestRange() that receives array , array size n and k as parameters and returns the output range (as a pair in cpp and array of size 2 in java and python)

Expected Time Complexity : O(n * k *log k)
Expected Auxilliary Space : O(k)

Constraints:
1 <= K,N <= 500
0 <= a[ i ] <= 10^5*/

#include<bits/stdc++.h>
using namespace std;
#define N 1000 

class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k){
          //code here
          set<pair<int,pair<int,int>>> s;
          for(int i = 0; i < k; i++){
              s.insert({KSortedArray[i][0],{i,0}});
           }
           pair<int,int> range = {0,100000};
           int minDiff = INT_MAX;
           while(true){
               auto p1 = *s.rbegin(); 
               auto p2 = *s.begin(); 
               int row = p2.second.first,col = p2.second.second;
               int currDiff = p1.first - p2.first;
               if(currDiff < minDiff){
                   minDiff = currDiff;
                   range = {p2.first,p1.first};
                }
                int old_ele = KSortedArray[row][col];
                auto it = s.find({old_ele,{row,col}});
                s.erase(it);
                col++;
                if(col == n) 
                  break;
                int new_ele = KSortedArray[row][col];
                s.insert({new_ele,{row,col}});
            }
       return (range);
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i = 0; i < k; i++)
            for(int j = 0; j < n; j++)
            cin>>arr[i][j];
        Solution s;
        rangee = s.findSmallestRange(arr, n, k);
        cout<<rangee.first<<" "<<rangee.second<<endl;
    }
}