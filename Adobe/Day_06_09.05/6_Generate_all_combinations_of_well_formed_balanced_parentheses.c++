/*Given an integer N representing the number of pairs of parentheses, the task is to generate all combinations of well-formed(balanced) parentheses.

Example 1:

Input:
N = 3

Output:
((()))
(()())
(())()
()(())
()()()

Example 2:

Input:
N = 1

Output:
()

Your Task:  
You don't need to read input or print anything. Complete the function AllParenthesis() which takes N as input parameter and returns the list of balanced parenthesis.

Expected Time Complexity: O(2N * N).
Expected Auxiliary Space: O(2*N*X), X = Number of valid Parenthesis.

Constraints:
1 ≤ N ≤ 12
*/

#include<bits/stdc++.h>
using namespace std;

vector<string> AllParenthesis(int n);
// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution{
    public:
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        int open = n;
        int close = n;
        vector<string>ans;
        string temp = "";
        helper(ans,open,close,temp);
        return ans;
    }
    
    void helper(vector<string>&ans,int open,int close,string &temp){
        if(open == 0 && close == 0){
            ans.push_back(temp);
            return;
        }
        if(open != 0){
            string op1 = temp + '(';
            helper(ans,open-1,close,op1);
        }
        if(close > open){
            string op2 = temp + ')';
            helper(ans,open,close-1,op2);
        }
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Solution s;
        vector<string> res = s.AllParenthesis(n);
        sort(res.begin(), res.end());
        for(int i = 0; i < res.size(); i++){
            cout<<res[i]<<"endl";
        }
    }
    return 0;
}