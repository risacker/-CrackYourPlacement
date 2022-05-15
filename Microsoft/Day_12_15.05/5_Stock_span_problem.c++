/*The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stocks price for all n days. 
The span Si of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

Example 1:

Input: 
N = 7, price[] = [100 80 60 70 60 75 85]

Output:
1 1 1 2 1 4 6

Explanation:
Traversing the given input span for 100 will be 1, 80 is smaller than 100 so the span is 1, 60 is smaller than 80 so the span is 1, 70 is greater than 60 so the span is 2 and so on. Hence the output will be 1 1 1 2 1 4 6.

Example 2:

Input: 
N = 6, price[] = [10 4 5 90 120 80]

Output:
1 1 2 4 5 1

Explanation:
Traversing the given input span for 10 will be 1, 4 is smaller than 10 so the span will be 1, 5 is greater than 4 so the span will be 2 and so on. Hence, the output will be 1 1 2 4 5 1.

User Task:
The task is to complete the function calculateSpan() which takes two parameters, an array price[] denoting the price of stocks, and an integer N denoting the size of the array and number of days. 
This function finds the span of stock's price for all N days and returns an array of length N denoting the span for the i-th day.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 10^5
1 ≤ C[i] ≤ 10^5
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n){
       // Your code here
       stack<int>s;
       vector<int>v;
       s.push(0);
       v.push_back(1);
       for(int i = 1; i < n; i++){
          while(s.empty() == false && price[s.top()] <= price[i]){
              s.pop();
          }
          int span = s.empty()? i+1 : i-s.top();
          v.push_back(span);
          s.push(i);
      }
      return v;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int i,arr[N];
        for(int i = 0; i < N; i++){
            cin>>arr[i];
        }
        Solution s;
        vector<int> res = s.calculateSpan(arr, N);
        for(int i = 0; i < res.size(); i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
}